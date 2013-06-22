import bluetooth

data_sent = False

def getTimeoutDuration():
    #Get the timeout duration form the Phone app(settings in app)
    return 8  


def getDevices():
    nearby_devices = bluetooth.discover_devices(duration=getTimeoutDuration())

    for bdaddr in nearby_devices:
    #        if target_name == bluetooth.lookup_name( bdaddr ):
    #            target_address = bdaddr
    #            break
    #    print bluetooth.lookup_name(bdaddr),bluetooth.socket.create_connection(bdaddr)
        print bluetooth.lookup_name(bdaddr)
    
    #    if (target_address is not None) and (not data_sent):
    #        #print "found target bluetooth device with address ", target_address
    #        # send_data()
    #        data_sent = True
    #    else:
    #        #print "could not find target bluetooth device nearby"
    #        # to mark 'connection dropped'
    #        data_sent = False
    
    #    time.sleep(1)
