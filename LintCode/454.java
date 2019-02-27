public class Rectangle {
	/*
	 * Define two public attributes width and height of type int.
	 */
	private int width;
	private int height;

	/*
	 * Define a constructor which expects two parameters width and height here.
	 */
	public Rectangle(int w, int h) {
		this.width = w;
		this.height = h;
	}

	/*
	 * Define a public method `getArea` which can calculate the area of the
	 * rectangle and return.
	 */
	public int getArea() {
		return this.height * this.width;
	}

}
