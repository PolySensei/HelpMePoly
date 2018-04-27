class Book{

    String title;
    String author;
    double price;
    protected int pages;

    //constructor
    Book(String title, String author, double newPrice, int numpages){
        title = title;
        author = author;
        price = newPrice;
	pages=numpages;

    }
    Book(){
	
    }
//setTitle
//setAuthor
//setPages
    public String getTitle(){
        return title;
    }
    public String getAuthor(){
        return author;
    }
    public double getPrice(){
        return price;
    }
    public int getPages(){
        return pages;
    }
    public void setPrice(double newPrice){
	price = newPrice;
    }
}
