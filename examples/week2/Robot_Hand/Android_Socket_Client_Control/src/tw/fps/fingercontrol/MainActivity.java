package tw.fps.fingercontrol;

import java.io.BufferedWriter;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends ActionBarActivity implements OnClickListener {
	private Socket socket;
	private Button BtnSend;

	private static final int rpiServerPort = 54321;
	private static final String rpiServerIp = "192.168.0.108";
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		new Thread(new ClientThread()).start();
		
//		Button BtnSend = (Button) findViewById(R.id.BtnSend);
//		BtnSend.setOnClickListener(this);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	public void onClick(View view) {
//		try {
//			EditText et = (EditText) findViewById(R.id.EtMsg);
//			String str = et.getText().toString();
//			PrintWriter out = new PrintWriter(new BufferedWriter(
//					new OutputStreamWriter(socket.getOutputStream())),
//					true);
//			out.println(str);
//		} catch (UnknownHostException e) {
//			e.printStackTrace();
//		} catch (IOException e) {
//			e.printStackTrace();
//		} catch (Exception e) {
//			e.printStackTrace();
//		}
	}

	class ClientThread implements Runnable {

		@Override
		public void run() {

		    InetAddress serverAddr = null;
	        SocketAddress sc_add = null;
	        Socket socket = null;
	        String message = "Hello Socket";
	        
			try {
				serverAddr = InetAddress.getByName(rpiServerIp);
				sc_add= new InetSocketAddress(serverAddr,rpiServerPort);
				
				socket = new Socket();				
				socket.connect(sc_add,3000);
				
				DataOutputStream out = new DataOutputStream(socket.getOutputStream());
				out.writeUTF(message);
				
			} catch (UnknownHostException e) {
			} catch (SocketException e) {		
			} catch(IOException e) {
			} 

		}

	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}
}
