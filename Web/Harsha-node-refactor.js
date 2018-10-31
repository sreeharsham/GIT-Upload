// Refactor this as best as you can.

fs = require('fs');
// songs
/*
imagine = ['c', 'cmaj7', 'f', 'am', 'dm', 'g', 'e7'];
somewhere_over_the_rainbow = ['c', 'em', 'f', 'g', 'am'];
tooManyCooks = ['c', 'g', 'f'];
iWillFollowYouIntoTheDark = ['f', 'dm', 'bb', 'c', 'a', 'bbm'];
babyOneMoreTime = ['cm', 'g', 'bb', 'eb', 'fm', 'ab'];
creep = ['g', 'gsus4', 'b', 'bsus4', 'c', 'cmsus4', 'cm6'];
army = ['ab', 'ebm7', 'dbadd9', 'fm7', 'bbm', 'abmaj7', 'ebm'];
paperBag = ['bm7', 'e', 'c', 'g', 'b7', 'f', 'em', 'a', 'cmaj7',
            'em7', 'a7', 'f7', 'b'];
toxic = ['cm', 'eb', 'g', 'cdim', 'eb7', 'd7', 'db7', 'ab', 'gmaj7',
         'g7'];
bulletproof = ['d#m', 'g#', 'b', 'f#', 'g#m', 'c#'];*/
song_11 = [];


//READ as Objects
var chordsAndLables = {
    imagine: {
        chords: ['c', 'cmaj7', 'f', 'am', 'dm', 'g', 'e7'],
        label: "easy"
    },
    somewhere_over_the_rainbow: {
        chords: ['c', 'em', 'f', 'g', 'am'],
        label: "easy"
    },
    tooManyCooks: {
        chords: ['c', 'g', 'f'],
        label: "easy"
    },
iWillFollowYouIntoTheDark: {
        chords: ['f', 'dm', 'bb', 'c', 'a', 'bbm'],
        label: "medium"
    },
babyOneMoreTime: {
        chords: ['cm', 'g', 'bb', 'eb', 'fm', 'ab'],
        label: "medium"
    },
creep: {
        chords: ['g', 'gsus4', 'b', 'bsus4', 'c', 'cmsus4', 'cm6'],
        label: "medium"
    },
army: {
        chords: ['ab', 'ebm7', 'dbadd9', 'fm7', 'bbm', 'abmaj7', 'ebm'],
        label: "hard"
    },
paperBag: {
        chords: ['bm7', 'e', 'c', 'g', 'b7', 'f', 'em', 'a', 'cmaj7','em7', 'a7', 'f7', 'b'],
        label: "hard"
    }, 
    
toxic: {
        chords: ['cm', 'eb', 'g', 'cdim', 'eb7', 'd7', 'db7', 'ab', 'gmaj7','g7'],
        label: "hard"
    },
bulletproof: {
        chords: ['d#m', 'g#', 'b', 'f#', 'g#m', 'c#'],
        label: "hard"
    }
    
}

console.log(chordsAndLables.toxic.label);




var songs = []; //label, chords
var labels = []; //levels
var allChords = []; //list of all chords
var labelCounts = []; //labels and counts of songs
var labelProbabilities = []; //probability of each label
var chordCountsInLabels = {};//chord count per label
var probabilityOfChordsInLabels = {};//probability of chord per label

//FUNCTION1. chords contains chordarray of songs, label is the level. Push level, chordarray into songs. Push level into labels.
//As long as chords not in all Chords, add it into allChords. labelCounts??



function train(chords, label){
  songs.push([label, chords]);
  labels.push(label);
  for (var i = 0; i < chords.length; i++){
    if(!allChords.includes(chords[i])){
      allChords.push(chords[i]);
    }
  }
  if(!!(Object.keys(labelCounts).includes(label))){
    labelCounts[label] = labelCounts[label] + 1;
  } else {
    labelCounts[label] = 1;
  }

   //console.log(chords, labels);
};

//FUNCTION3. returns length of songs array
function getNumberOfSongs(){
   return songs.length;
};

//FUNCTION2. goes to getNumberOfSongs, gets 9 and sets probability of 3/9 to all??
function setLabelProbabilities(){
  Object.keys(labelCounts).forEach(function(label){
    var numberOfSongs = getNumberOfSongs();
    labelProbabilities[label] = labelCounts[label] / numberOfSongs;
  });
//console.log(labelProbabilities);
};

//FUNCTION4 pushes chords used per level in chordCountsInLabels
function setChordCountsInLabels(){
  songs.forEach(function(i){
    if(chordCountsInLabels[i[0]] === undefined){
      chordCountsInLabels[i[0]] = {};
    }
    i[1].forEach(function(j){
      if(chordCountsInLabels[i[0]][j] > 0){
        chordCountsInLabels[i[0]][j] =
chordCountsInLabels[i[0]][j] + 1;
      } else {
        chordCountsInLabels[i[0]][j] = 1;
      }
    });
  });
//console.log(chordCountsInLabels);
}

//FUNCTION5 probability of each chord in the label
function setProbabilityOfChordsInLabels(){
  probabilityOfChordsInLabels = chordCountsInLabels;
  Object.keys(probabilityOfChordsInLabels).forEach(function(i){
    Object.keys(probabilityOfChordsInLabels[i]).forEach(function(j){
      probabilityOfChordsInLabels[i][j] =
probabilityOfChordsInLabels[i][j] * 1.0 / songs.length;
    });
  });
//console.log(probabilityOfChordsInLabels);
}


/*
train(imagine, 'easy');
train(somewhere_over_the_rainbow, 'easy');
train(tooManyCooks, 'easy');
train(iWillFollowYouIntoTheDark, 'medium');
train(babyOneMoreTime, 'medium');
train(creep, 'medium');
train(paperBag, 'hard');
train(toxic, 'hard');
train(bulletproof, 'hard');*/


//console.log(songs);      easy, chords
//console.log(labels);     levels
//console.log(allChords);  //list of all chords
//console.log(labelCounts);//all unique chords

//console.log(chordCountsInLabels); chords with levels and times used in the level



setLabelProbabilities(); //??
setChordCountsInLabels();
setProbabilityOfChordsInLabels();




function classify(chords){
  //console.log(chords);
    var ttal = labelProbabilities;
  console.log(ttal);
  var classified = {};
  Object.keys(ttal).forEach(function(obj){
    var first = labelProbabilities[obj] + 1.01;
    chords.forEach(function(chord){
      var probabilityOfChordInLabel =
probabilityOfChordsInLabels[obj][chord];
       // console.log(probabilityOfChordsInLabels);
      if(probabilityOfChordInLabel === undefined){
        first + 1.01;
      } else {
        first = first * (probabilityOfChordInLabel + 1.01);
      }
    });
    classified[obj] = first;
  });
 //console.log("END of TTAL");
    console.log(classified);
   // console.log("END");
};

classify(['d','g', 'e', 'dm']);
//classify(['f#m7', 'a', 'dadd9', 'dmaj7', 'bm', 'bm7', 'd', 'f#m']);