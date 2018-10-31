var express = require('express');
var router = express.Router();
var path = require('path');
var http = require('http');
var https = require('https');




//router.get('/data', function(req,res){
//	res.json([{"id": 1, "name": "Mymm", "city": "Pantano do Sul"},
//        {"id": 2, "name": "Skyble", "city": "Guilmaro"},
//        {"id": 3, "name": "Tagfeed", "city": "Gnosjö"},
//        {"id": 4, "name": "Realcube", "city": "Jrashen"},
//        {"id": 5, "name": "Bluejam", "city": "Zhangjiawo"},
//        {"id": 6, "name": "Jayo", "city": "Obonoma"},
//        {"id": 7, "name": "Cogidoo", "city": "Sungsang"},
//        {"id": 8, "name": "Avavee", "city": "Diawara"},
//        {"id": 9, "name": "Tagtune", "city": "Monywa"},
//        {"id": 10, "name": "Centimia", "city": "Retkovci"}]);
//});
var profile = "";
var maingraph = [];
var request = https.get("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=MSFT&apikey=demo", function(response){
        console.log("inside");
//        console.log(request);
		var body = "";

		response.on("data", function(chunk){
			body += chunk;
		});

		response.on("end", function(){
			if(response.statusCode === 200){
			try{
			profile = JSON.parse(body);
//                var arr1 = [];
//                arr1.push(profile.badges);
//			var message = " has " + profile.badges.length + " total badge(s) and " + profile.points.JavaScript + " points in Javascript ";
//	console.log(message);
////                console.log(arr1);
//                console.log(profile.badges[0]['id']);
//                console.log(profile['Meta Data']['1. Information']);
//                console.log(Object.keys(profile['Time Series (Daily)']));
                var key = Object.keys(profile['Time Series (Daily)']);
//                console.log(key[0]);
                console.log(key.length);
                for (var i =0; i < key.length; i++)
                    {
                        
                        console.log(i + " " + profile['Time Series (Daily)'][key[i]]['1. open']);
                    }
//                console.log(profile['Time Series (Daily)'][key[0]]['1. open']);
		}
		catch(error){
//			printError(error);
		}
	}
	else{
//		printError({message: "There was an error getting profile for " + username + "."})
	}
		});
	});


/* GET home page. */
router.get('/', function(req, res, next) {
    res.sendFile(path.join(__dirname, '../', 'views', 'index.html'));
//  res.render('index', { title: 'Express' });
});

router.get('/data', function(req,res){
res.json(profile);
//alert(profile);
});


module.exports = router;
