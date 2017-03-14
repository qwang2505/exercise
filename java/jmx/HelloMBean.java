package jmx;

public interface HelloMBean {
    // management attributes
    public String getName();
    public void setName(String name);
    // management operations
    public void print();
}
