import json
import wiotp.sdk.device
import time

myConfig = {
    "identity": {
    "orgId": "zc4u6v",
    "typeId": "rio123",
    "deviceId": "iotid"
 
    },
    "auth": {
        "token": "3fXCvofGYUdQy3raGN"
    }
}
client = wiotp.sdk.device.Deviceclient(config=myconfig, logHandlers=None)
client.connect()

while True:
        name= "Smartbridge"
        #in area location

        latitude=17.4225176
        longitude=78.5458842

        #out area location

        #latitude=17.4219272
        #longitude=78.5488783

        myData={'name': name, 'lat': latitude,'lon': longitude}
        client.publishEvent(eventId="status",msgformat="json", data=mydata, qos=0, onpublish=None)
        print("Data published to IBM IOT platform :",myData)
        time.sleep(5)
        
client.disconnect()
