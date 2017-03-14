package jmx;

import java.lang.management.ManagementFactory;
import java.net.InetAddress;
import java.rmi.registry.LocateRegistry;
import java.rmi.server.RMISocketFactory;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.atomic.AtomicBoolean;

import javax.management.MBeanServer;
import javax.management.ObjectName;
import javax.management.remote.JMXAuthenticator;
import javax.management.remote.JMXConnectorServer;
import javax.management.remote.JMXConnectorServerFactory;
import javax.management.remote.JMXPrincipal;
import javax.management.remote.JMXServiceURL;
import javax.management.remote.rmi.RMIConnectorServer;
import javax.security.auth.Subject;

public class JmxServer {

    private final AtomicBoolean runningFlag = new AtomicBoolean(true);
    
    /**
     * @param args
     * @throws InterruptedException
     */
    public static void main(String[] args) throws InterruptedException {
        try {
            MBeanServer mbs = ManagementFactory.getPlatformMBeanServer();

            String addr = "10.12.0.5:31999";//本机的话ip地址可以使用localhost或者127.0.0.1
            JMXServiceURL address = new JMXServiceURL("service:jmx:rmi://"
                    + addr + "/jndi/rmi://" + addr + "/jmxrmi");

            Map<String, Object> jmxEnvironment = new HashMap<String, Object>();
            jmxEnvironment.put("jmx.remote.credentials", new String[] { "saf",
                    "asswrd" });

            InetAddress ipInterface = InetAddress.getByName("10.74.169.50");
            RMISocketFactory rmiFactory = RMISocketFactory.getDefaultSocketFactory();
                    //new AnchorSocketFactory(ipInterface,"false");
            LocateRegistry.createRegistry(31999, null, rmiFactory);
            
             // 這個是必須的，否則報 no such object in table之類是異常！！！！ 花了相當長時間才發現這點
            jmxEnvironment.put(
                    RMIConnectorServer.RMI_SERVER_SOCKET_FACTORY_ATTRIBUTE,
                    rmiFactory);

            // 需要认证则这么写：
//            JMXAuthenticator auth = createJMXAuthenticator();
//            jmxEnvironment.put(JMXConnectorServer.AUTHENTICATOR, auth);

            JMXConnectorServer connector = JMXConnectorServerFactory
                    .newJMXConnectorServer(address, jmxEnvironment,
                            ManagementFactory.getPlatformMBeanServer());
            HelloMBean mbean = new Hello();
            ObjectName testMBeanName = new ObjectName(
                    "helloMBean:name=helloMBean");
            testMBeanName = new ObjectName("helloMBeanDomain", "type",
                    "HelloMBean");
            mbs.registerMBean(mbean, testMBeanName);

            connector.start();
        } catch (Exception e) {
            e.printStackTrace();
        }

//        try {//这个好像没用
//            synchronized (this) {
//                while (runningFlag.get()) {
//                    this.wait();
//                }
//            }
//        } catch (Exception e) {
//
//        }
    }

    private JMXAuthenticator createJMXAuthenticator() {
        return new JMXAuthenticator() {
            public Subject authenticate(Object credentials) {
                String[] sCredentials = (String[]) credentials;
                if (null == sCredentials || sCredentials.length != 2) {
                    throw new SecurityException("Authentication failed!");
                }
                String userName = sCredentials[0];
                String pValue = sCredentials[1];
                if ("saf".equals(userName) && "asswrd".equals(pValue)) {
                    Set principals = new HashSet();
                    principals.add(new JMXPrincipal(userName));
                    return new Subject(true, principals, Collections.EMPTY_SET,
                            Collections.EMPTY_SET);
                }
                throw new SecurityException("Authentication failed!");
            }
        };
    }

}
