
public class StringPlay {

	public static void main(String[] args) {
		String one = "C++ is cool";
		String two = "I love Java";
		String three = "The Same";
		String four = "the same";
		
		String five = two.substring(7)+one.substring(3);
		System.out.println(five);
		
		System.out.println(three == four);
		System.out.println(three.equals(four));
		System.out.println(three.equalsIgnoreCase(four));
	}
}
