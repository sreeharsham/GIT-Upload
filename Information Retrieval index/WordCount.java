import java.io.IOException;
import java.util.StringTokenizer;
import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapred.FileSplit;
import org.apache.hadoop.mapreduce.InputSplit;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class WordCount {

  public static class TokenizerMapper
       extends Mapper<Object, Text, Text, Text>{

    private final static IntWritable one = new IntWritable(1);
    private Text word = new Text();
    public void map(Object key, Text value, Context context
                    ) throws IOException, InterruptedException {
      Text docId;
      StringTokenizer itr = new StringTokenizer(value.toString());
      if (itr.hasMoreTokens()){
      docId = new Text(itr.nextToken());
      //private final static IntWritable key = new IntWritable(key);
      while (itr.hasMoreTokens()) {
        String token = itr.nextToken();
        token = token.replaceAll("[^a-zA-Z ]", "").toLowerCase().trim();
        word.set(token);
        context.write(word, docId);
      }
    }
   }
  }

  public static class IntSumReducer
       extends Reducer<Text,Text,Text,Text> {
    private IntWritable result = new IntWritable();

    public void reduce(Text key, Iterable<Text> values,
	                      Context context
                       ) throws IOException, InterruptedException {
      HashMap<String, Integer> wordMap = new HashMap<>();
      int sum = 0;
      for (Text val : values) {
        //sum += val.get();
        String word = val.toString();
        if (!wordMap.containsKey(word)){
                wordMap.put(word, 1);

        }
        else {
                wordMap.put(word, wordMap.get(word) + 1);
        }
      }
      StringBuilder tokenEntry = new StringBuilder();
      for (String s: wordMap.keySet()) {
        tokenEntry.append(s + ":" + Integer.toString(wordMap.get(s)) + "\t");
        }
      Text result = new Text(tokenEntry.toString());
      context.write(key, result);
    }
  }

  public static void main(String[] args) throws Exception {
    Configuration conf = new Configuration();
    Job job = Job.getInstance(conf, "word count");
    job.setJarByClass(WordCount.class);
    job.setMapperClass(TokenizerMapper.class);
//  job.setCombinerClass(IntSumReducer.class);
    job.setReducerClass(IntSumReducer.class);
    job.setOutputKeyClass(Text.class);
    job.setOutputValueClass(Text.class);
    FileInputFormat.addInputPath(job, new Path(args[0]));
    FileOutputFormat.setOutputPath(job, new Path(args[1]));
    System.exit(job.waitForCompletion(true) ? 0 : 1);
  }
}
