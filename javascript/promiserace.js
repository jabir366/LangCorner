var controller = new AbortController();
const sam =function(a){
    return new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve("A finished before!"+a);
        }, 1100);
    });
}
    // controller.signal.addEventListener('abort',()=>{
    //     reject('oops')
    // });
    // for(i=0;i<10000000;i++)
    //     {
    //         if(i%10000 ==0) console.log(i);
    //     }
    // }
// ); }
        //
   // a = setInterval(()=>{console.log("Checking")} ,500)  })} 
    // clearInterval(a);
    // resolve("A finshed");
const b = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve("B finished!");
    }, 1000);
});

const cancellablePromise = (promiseToCancel) => {
      let cancel
      const promise = new Promise((resolve, reject) => {
              cancel = reject
              promiseToCancel
                .then(resolve)
                .catch(reject)
            })
      return {promise, cancel}
}

const waitAndExecute = (time, functionToExecute) => new Promise((resolve, reject) => {
      timeInMs = time * 1000
      setTimeout(()=>{
              console.log(`Waited ${time} secs`)
              resolve(functionToExecute())
            }, timeInMs)
})

async function main (){
    // const finishString = await Promise.race([sam('sss'), b]).catch((e)=>console.log(e));
       const finishString = await fulfillWithTimeLimit(10,sam('sss'),null);
    //
    console.log(finishString);
}
async function fulfillWithTimeLimit(timeLimit, task, failureValue){
    let timeout;
    const timeoutPromise = new Promise((resolve, reject) => {
        timeout = setTimeout(() => {
            resolve(failureValue);
        }, timeLimit);
    });
    const response = await Promise.race([task, timeoutPromise]);
    if(timeout){ //the code works without this but let's be safe and clean up the timeout
        console.log("YESSS")
        clearTimeout(timeout);
        controller.abort();
        // clearInterval(a);
    }
    return response;
}

var poll = (promiseFn, duration,arg) => promiseFn().then(
             sleep(duration).then(() => poll(promiseFn, duration)));
const winston = require('winston');
const { combine, timestamp, json,colorize } = winston.format;
const logger = winston.createLogger({
    format: combine(timestamp(),
        colorize({ all: true }),
        json()),
    transports: [
        new winston.transports.Console(),
        new winston.transports.File({
          filename: 'combined.log',
        })
    ]
});

// logger.info('What rolls down stairs');
// logger.info('alone or in pairs,');
// logger.info('and over your neighbors dog?');
// logger.warn('Whats great for a snack,');
// logger.info('And fits on your back?');
// logger.error('Its log, log, log');
main().then(()=>console.log('hi',__dirname))

