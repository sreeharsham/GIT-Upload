package com.example.harsha.stocks;

import android.os.AsyncTask;

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

public class PriceandVolume extends AsyncTask<Void, Void, Void> {
    String pnvdata = "";
    String url = "http://harsha-env.us-east-2.elasticbeanstalk.com/autocomplete/";
    String smaurl = "http://harsha-env.us-east-2.elasticbeanstalk.com/sma/";
    String emaurl = "http://harsha-env.us-east-2.elasticbeanstalk.com/ema/";
    String stochurl = "http://harsha-env.us-east-2.elasticbeanstalk.com/stoch/";
    String bbandsurl = "http://harsha-env.us-east-2.elasticbeanstalk.com/bbands/";
    String cciurl = "http://harsha-env.us-east-2.elasticbeanstalk.com/cci/";
    String adxurl = "http://harsha-env.us-east-2.elasticbeanstalk.com/adx/";
    String priceurl = "http://harsha-env.us-east-2.elasticbeanstalk.com/table/";
    String rsiurl = "http://harsha-env.us-east-2.elasticbeanstalk.com/rsi/";
    String newsurl = "http://harsha-env.us-east-2.elasticbeanstalk.com/xml/";
    String macdurl = "http://harsha-env.us-east-2.elasticbeanstalk.com/macd/";
    @Override
    protected Void doInBackground(Void... voids) {

        try {
            URL url = new URL("http://harsha-env.us-east-2.elasticbeanstalk.com/table/");
            HttpURLConnection httpURLConnection = (HttpURLConnection) url.openConnection();
            InputStream inputStream = httpURLConnection.getInputStream();
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
            String line = "";
            while (line != null) {
                line = bufferedReader.readLine();
                pnvdata = pnvdata + line;
            }
            JSONObject pnvreader = new JSONObject(pnvdata);





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
    }
}
