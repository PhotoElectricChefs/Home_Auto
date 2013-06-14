/**
 * 
 */
package com.pec.ha;

/**
 * This class in the last layer, can be understood as L2 in the OSI model.
 *
 *It must transmit the data sent to it in the proper format.
 *It is also responsible to receiving data.
 *
 *
 * @author ashfaq
 * 
 */
public class AirInterface {

	private static AirInterface airInterface = null;

	private AirInterface() {
	}

	public static AirInterface getInstance() {
		if (airInterface == null) {
			airInterface = new AirInterface();
		}
		return airInterface;
	}
	 
	 public void transmit(){
		 
	 }
	 
	 public DataStructure recieve(){
		 return null;
	 }
}
