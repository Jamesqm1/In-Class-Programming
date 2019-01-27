/**
 * @author Mark Baldwin
 *
 */
public class Friend {
	private String name;
	private String email;
	
	public Friend() {
		name = "John Smith";
		email = "N/A";
	}
	
	public Friend(String n, String e) {
		name = n;
		email = e;
	}
	
	public String getName() {
		return name;
	}
	
	public String getEmail() {
		return email;
	}
	
	public void setEmail(String e) {
		name = e;
	}
	
//	public String toString() {
//		return name + " " + email;
//	}
	
	
	
}
