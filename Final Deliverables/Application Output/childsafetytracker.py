import json
import wiotp.sdk.device
import time

myConfig = {
    "identity": {
    "orgId": "zc4u6v",
    "typeId": "ChildSafety",
    "deviceId": "Childtracker"
 
    },
    "auth": {
        "token": "childsafety123"
    }
}
client = wiotp.sdk.device.DeviceClient(config=myConfig, logHandlers=None)
client.connect()

while True:
        name= "Smartbridge"
        latitude=17.4225176
        longitude=78.5458842

        myData={'name': name, 'lat': latitude,'lon': longitude}
        client.publishEvent(eventId="status",msgFormat="json", data=myData, qos=0, onPublish=None)
        print("Data published to IBM IOT platform :",myData)
        time.sleep(5)
        
client.disconnect()
