import java.net.*;
import java.io.*;

public class Server {
    public static void main(String[] args) throws Exception {
        DatagramSocket socket = new DatagramSocket(5000);
        byte[] buffer = new byte[65535];

        System.out.println("Server is ready to receive file...");

        // Receive file name
        DatagramPacket fileNamePacket = new DatagramPacket(buffer, buffer.length);
        socket.receive(fileNamePacket);
        String fileName = new String(fileNamePacket.getData(), 0, fileNamePacket.getLength());

        FileOutputStream fos = new FileOutputStream("received_" + fileName);

        while (true) {
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
            socket.receive(packet);

            String msg = new String(packet.getData(), 0, packet.getLength());

            // End signal
            if (msg.equals("END")) {
                break;
            }
            

            fos.write(packet.getData(), 0, packet.getLength());

            // Send ACK
            String ack = "ACK";
            DatagramPacket ackPacket = new DatagramPacket(ack.getBytes(), ack.length(), packet.getAddress(), packet.getPort());
            socket.send(ackPacket);
        }

        fos.close();
        socket.close();

        System.out.println("File received successfully!");
    }
}