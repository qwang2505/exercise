package jmx;

public class Hello implements HelloMBean {

    private String name = "";

    public String getName() {
    return name;
    }

    public void setName(String name) {
    this.name = name;
    }

    public void print() {
    System.out.println("Hello, " + name + "!!" );
    }
}
