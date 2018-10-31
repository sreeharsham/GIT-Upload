var app = angular.module('renderExample',[]);
app.controller('renderExampleController', function($scope){
	$scope.showContent= true;
	$scope.label= 'Hide Text';
 
	$scope.switch = function(){
		if($scope.showContent){
			$scope.showContent= false;
			$scope.label= 'Show Text';
		}else{
			$scope.showContent= true;
			$scope.label= 'Hide Text';			
		}
	}
});