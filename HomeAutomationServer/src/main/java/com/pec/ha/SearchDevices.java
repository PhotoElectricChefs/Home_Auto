/**
 * 
 */
package com.pec.ha;


/**
 * This class is responsible for searching devices and to find the existance of
 * a new node. Then to create/configure the node.
 * 
 * @author ashfaq
 * 
 */
public class SearchDevices {

	private static SearchDevices searchDevices = null;

	private SearchDevices() {
	}

	public static SearchDevices getInstance() {
		if (searchDevices == null) {
			searchDevices = new SearchDevices();
		}
		return searchDevices;
	}
	
	/**
	 * This method broadcasts asking all nodes in the area to respond with its
	 * address
	 */
	public void startScan(){
		String[] addresses;
		NodeRepo.clearNodeMap();
		//TODO: Send code to make node broadcast their address
		addresses = null;//TODO: Receive address in an array
		addNodesToNodeMap(addresses);
	}
	private void addNodesToNodeMap(String[] addresses) {
		for (String address : addresses) {
			NodeRepo.addNode(address, new Node(address));
		}
		
	}
}
