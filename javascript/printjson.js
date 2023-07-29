const fs=require('fs');



function main (){
    var myjson = {
      "version": "1.0",
      "message_id": "1234567890",
      "type": "PFCP_ASSOCIATION_SETUP_REQUEST",
      "seid": "1234567890",
      "gtp_teid": 1234,
      "apn": "internet",
      "bearer_contexts": [
        {
          "id": 1,
          "qci": 5,
          "pfcp_flavour": "IPv4",
          "upf_ip_address": "192.168.1.1",
          "upf_port": 2152
        }
      ]
    }
    
    const escapedj = JSON.stringify(myjson,null,2).replace(/"/g,'\\"'); 
    fs.writeFileSync('output.h',escapedj);
    console.log("File written to output.h");

}

main();
