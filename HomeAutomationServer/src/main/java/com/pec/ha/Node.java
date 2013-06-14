/**
 * 
 */
package com.pec.ha;

/**
 * 
 * This class have the blue print for the node attached away from the Pi.
 * 
 * 
 * @author ashfaq
 */
public class Node {

	String Address;
	String State;
	String TransmitID;
	String RecieveID;

	public Node(String address) {
		Address = address;
	}

	public String getAddress() {
		return Address;
	}

	public void setAddress(String address) {
		Address = address;
	}

	public String getState() {
		return State;
	}

	public void setState(String state) {
		State = state;
	}

	public String getTransmitID() {
		return TransmitID;
	}

	public void setTransmitID(String transmitID) {
		TransmitID = transmitID;
	}

	public String getRecieveID() {
		return RecieveID;
	}

	public void setRecieveID(String recieveID) {
		RecieveID = recieveID;
	}

}
