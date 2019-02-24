/*
 *
 * This function simply prints any requested length of the Fibonacci series.
 *
 *
 */

function printFibonacciSeries(seriesLength){
    var x = [0,1];
    var iteration = 0;
    (function recursionSequence(n){
     if (n > 0){
     var nextArrayValue = x[iteration] + x[iteration+1];
     x.push(nextArrayValue);
     n--;
     iteration++
     recursionSequence(n);
     } else {
     for (i=0; i < iteration; i++ ){
     console.log(x[i]);
     }
     }
     })(seriesLength) // attempting to invoke the function. . . . and it works!
    
    // for testing. . . .  actually can't i jsut invoke this immediately after declaring it?
    //recursionSequence(seriesLength);
}

//PIzza
