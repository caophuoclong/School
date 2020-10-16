package Buoi3;

public class Gach {
	private String id;
	private String color;
	private int item_in_Box;
	private int long_item;
	private int width_item;
	private long price;
	public Gach(){
		id = "001";
		color = "black";
		item_in_Box = 10;
		long_item = 15;
		width_item = 15;
		price = 50000;
	}
	public Gach(String id1, String color1, int quanity, int long_item1,int width_item1, long price1){
		this.id = id1;
		this.color = color1;
		this.item_in_Box = quanity;
		this.long_item = long_item1;
		this.width_item = width_item1;
	}
	
	
	
	

}
