/**
* @param {number} m
* @param {number} n
* @return {number}
*/
var uniquePaths = function(m, n) {
   if(m <= 0 || n <= 0){
       return 0;
   }

   var res = 1;
   for(var i = n; i < m+n-1; i++){
       res = res * i/(i-n+1);
   }

   return Math.round(res);
};
