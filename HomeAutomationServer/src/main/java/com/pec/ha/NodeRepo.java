/**
 * 
 */
package com.pec.ha;

import java.util.HashMap;
import java.util.Map;

/**
 * 
 * This class stores all the nodes as a map, with address as the key.
 * Any access to nodes must be done from this class
 * @author ashfaq
 * 
 */
public class NodeRepo {

	private static Map<String, Node> nodeMap = new HashMap<String, Node>();

	public static Node getNode(String address) {
		return nodeMap.get(address);
	}

	public static void addNode(String address, Node node) {
		nodeMap.put(address, node);
	}

	/**
	 * This method creates a back up of node map in case of any failures.
	 */
	private void exportNodeMap() {
		// TODO implement a csv export code
	}

	private void importNodeMap() {
		// TODO implement reading from the exported csv incase of power failure
		// etc
	}

	/**
	 * This method will be called when the user wants to refresh the list of
	 * nodes attached
	 */
	static void clearNodeMap() {
		nodeMap.clear();
	}

}
