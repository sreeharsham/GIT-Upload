package com.example.harsha.stocks;

import android.os.AsyncTask;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

/**
 * Created by win 8.1 on 11/19/2017.
 */

public class fetchData extends AsyncTask<Void, Void, Void> {
    String data = "";
    String finalnews = "";

//    String singleParsed = "";
//    ArrayList<HashMap<String, String>> newslist;

    @Override
    protected Void doInBackground(Void... voids) {
//        newslist = new ArrayList<>();
        try {
            URL url = new URL("http://harsha-env.us-east-2.elasticbeanstalk.com/xml/aapl");

            HttpURLConnection httpURLConnection = (HttpURLConnection) url.openConnection();
            InputStream inputStream = httpURLConnection.getInputStream();
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
            String line = "";
            while(line != null) {
                line = bufferedReader.readLine();
                data = data + line;
            }
//            JSONArray JA = new JSONArray(data);
//            for(int i=0; i<JA.length();i++) {
//                JSONObject JO = (JSONObject) JA.get(i);
//            }
            JSONObject reader = new JSONObject(data);
            data = reader.getString("rss");
            JSONObject reader1 = new JSONObject(data);
            data = reader1.getString("channel");
            JSONObject reader2 = new JSONObject(data);
            data = reader2.getString("item");
            JSONArray news = reader2.getJSONArray("item");
            int newscount = 0;
            for(int i = 0; i < news.length(); i++) {
//                if (newscount < 5){
                    JSONObject items = news.getJSONObject(i);
                if (items.getString("link").contains("article")) {
                    finalnews = finalnews + "TITLE" + items.getString("title") + "\n" +
                           "LINK" + items.getString("link") + "\n" +
                            "PUBDATE" + items.getString("pubDate") + "\n" +
                            "AUTHOR" + items.getString("sa:author_name");
//                    String title = items.getString("title");
//                    String link = items.getString("link");
//                    String pubdate = items.getString("pubDate");
//                    String authorname = items.getString("sa:author_name");
//                    HashMap<String, String> singlenews = new HashMap<>();
//                    singlenews.put("title", title);
//                    singlenews.put("link", link);
//                    singlenews.put("pubdate", pubdate);
//                    singlenews.put("authorname", authorname);
//                    newslist.add(singlenews);
                }
                finalnews = finalnews + "\n\n\n";
//                    newscount++;
//            }
            }

//            Iterator<String> iter = json.keys();
//            while (iter.hasNext()) {
//                String key = iter.next();
//                try {
//                    Object value = json.get(key);
//                } catch (JSONException e) {
//                    // Something went wrong!
//                }
//            }



        } catch (MalformedURLException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    protected void onPostExecute(Void aVoid) {
        super.onPostExecute(aVoid);


//        MainActivity.data.setText(this.finalnews);
    }
}
