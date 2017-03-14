package jmx;

import java.lang.management.ManagementFactory;
import java.lang.management.ThreadMXBean;
import java.util.HashMap;
import java.util.Map;

import javax.management.JMX;
import javax.management.MBeanServerConnection;
import javax.management.ObjectName;
import javax.management.remote.JMXConnector;
import javax.management.remote.JMXConnectorFactory;
import javax.management.remote.JMXServiceURL;

public class JmxClient {

    /**
     * @param args
     * @throws InterruptedException
     */
    public static void main(String[] args) throws InterruptedException {
        ObjectName hello_name = null;
        try {
            hello_name = new ObjectName("helloMBeanDomain", "type",
                    "HelloMBean");
            System.out.println("\tOBJECT NAME = " + hello_name);
            // service:jmx:rmi://%s:%d/jndi/rmi://%s:%d/jmxrmi
            String addr = "10.12.0.5:31999";
            JMXServiceURL address = new JMXServiceURL("service:jmx:rmi://"
                    + addr + "/jndi/rmi://" + addr + "/jmxrmi");
            System.out.println("JmxRemote.main()1");
            Map<String, Object> jmxEnvironment = new HashMap<String, Object>();

            // 如果服務端有认证，則客戶端也要这么写：
            // jmxEnvironment.put("jmx.remote.credentials", new String[] {
            // "saf", "asswrd"});

            JMXConnector connector = JMXConnectorFactory.connect(address,
                    jmxEnvironment);
            System.out.println("JmxRemote.main()2");
            MBeanServerConnection mbs = connector.getMBeanServerConnection();
            System.out.println("JmxRemote.main()3");
            ThreadMXBean threadBean = ManagementFactory.newPlatformMXBeanProxy(
                    mbs, ManagementFactory.THREAD_MXBEAN_NAME,
                    ThreadMXBean.class);
            System.out
                    .println(" getThreadCount " + threadBean.getThreadCount());// 线程数量

            MBeanServerConnection connection = connector
                    .getMBeanServerConnection();
            HelloMBean helloMBean = JMX.newMXBeanProxy(connection, hello_name,
                    HelloMBean.class);

            System.out.println("aaaaaaaa " + helloMBean);

            helloMBean.setName("LKKKKKKK ddd basdf");

            helloMBean.print();

            connector.close();

        } catch (Exception e) {
            e.printStackTrace();
            return;
        }
    }
}
