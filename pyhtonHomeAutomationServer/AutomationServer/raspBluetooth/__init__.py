import bluetooth
import time
import rpiBtConfig as cfg

def getTimeoutDuration():
    return 1

def getNewDevice():
    nearby_devices = bluetooth.discover_devices(duration=getTimeoutDuration())
    print nearby_devices
    for btaddr in nearby_devices:
        if bluetooth.lookup_name(btaddr)==cfg.newDeviceName():
            return btaddr    
    return None
    


#    for bdaddr in nearby_devices:
#        print bluetooth.lookup_name(bdaddr)
#    print nearby_devices
#    
#    while(1):
#        server_sock = bluetooth.BluetoothSocket()
#        server_sock.bind(("",3))
#        server_sock.listen(1)
#        client_socket, address = server_sock.accept()
#        
#        time.sleep(1)
    
#    client_sock = bluetooth.BluetoothSocket()
#    client_sock.connect((nearby_devices[0],3))
    
#    client_sock.bind()