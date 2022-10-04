package com.paulsofts.gfgfingerprintauthentication;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import android.Manifest;
import android.annotation.TargetApi;
import android.app.KeyguardManager;
import android.content.pm.PackageManager;
import android.hardware.fingerprint.FingerprintManager;
import android.os.Build;
import android.os.Bundle;
import android.security.keystore.KeyGenParameterSpec;
import android.security.keystore.KeyPermanentlyInvalidatedException;
import android.security.keystore.KeyProperties;
import android.widget.TextView;

import java.io.IOException;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.KeyStore;
import java.security.KeyStoreException;
import java.security.NoSuchAlgorithmException;
import java.security.NoSuchProviderException;
import java.security.UnrecoverableKeyException;
import java.security.cert.CertificateException;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;

public class MainActivity extends AppCompatActivity {

	private KeyStore keyStore;
	// Defining variable for storing
	// key in android keystore container
	private static final String KEY_NAME = "GEEKSFORGEEKS";
	private Cipher cipher;
	private TextView errorText;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		// Initializing KeyguardManager and FingerprintManager
		KeyguardManager keyguardManager = (KeyguardManager) getSystemService(KEYGUARD_SERVICE);
		FingerprintManager fingerprintManager = (FingerprintManager) getSystemService(FINGERPRINT_SERVICE);

		// Initializing our error text
		errorText = (TextView) findViewById(R.id.errorText);

		// Here, we are using various security checks
		// Checking device is inbuilt with fingerprint sensor or not
		if(!fingerprintManager.isHardwareDetected()){

			// Setting error message if device
			// doesn't have fingerprint sensor
			errorText.setText("Device does not support fingerprint sensor");
		}else {
			// Checking fingerprint permission
			if (ActivityCompat.checkSelfPermission(this, Manifest.permission.USE_FINGERPRINT) != PackageManager.PERMISSION_GRANTED) {
				errorText.setText("Fingerprint authentication is not enabled");
			}else{
				// Check for at least one registered finger
				if (!fingerprintManager.hasEnrolledFingerprints()) {
					errorText.setText("Register at least one finger");
				}else{
					// Checking for screen lock security
					if (!keyguardManager.isKeyguardSecure()) {
						errorText.setText("Screen lock security not enabled");
					}else{

						// if everything is enabled and correct then we will generate
						// the encryption key which will be stored on the device
						generateKey();
						if (cipherInit()) {
							FingerprintManager.CryptoObject cryptoObject = new FingerprintManager.CryptoObject(cipher);
							FingerprintHandler helper = new FingerprintHandler(this);
							helper.startAuth(fingerprintManager, cryptoObject);
						}
					}
				}
			}
		}
	}


	@TargetApi(Build.VERSION_CODES.M)
	protected void generateKey() {
		try {
			keyStore = KeyStore.getInstance("AndroidKeyStore");
		} catch (Exception e) {
			e.printStackTrace();
		}


		KeyGenerator keyGenerator;
		try {
			keyGenerator = KeyGenerator.getInstance(KeyProperties.KEY_ALGORITHM_AES, "AndroidKeyStore");
		} catch (NoSuchAlgorithmException | NoSuchProviderException e) {
			throw new RuntimeException("KeyGenerator instance failed", e);
		}

		try {
			keyStore.load(null);
			keyGenerator.init(new
					KeyGenParameterSpec.Builder(KEY_NAME,
					KeyProperties.PURPOSE_ENCRYPT |
							KeyProperties.PURPOSE_DECRYPT)
					.setBlockModes(KeyProperties.BLOCK_MODE_CBC)
					.setUserAuthenticationRequired(true)
					.setEncryptionPaddings(
							KeyProperties.ENCRYPTION_PADDING_PKCS7)
					.build());
			keyGenerator.generateKey();
		} catch (NoSuchAlgorithmException |
				InvalidAlgorithmParameterException
				| CertificateException | IOException e) {
			throw new RuntimeException(e);
		}
	}


	@TargetApi(Build.VERSION_CODES.M)
	public boolean cipherInit() {
		try {
			cipher = Cipher.getInstance(KeyProperties.KEY_ALGORITHM_AES + "/" + KeyProperties.BLOCK_MODE_CBC + "/" + KeyProperties.ENCRYPTION_PADDING_PKCS7);
		} catch (NoSuchAlgorithmException | NoSuchPaddingException e) {
			throw new RuntimeException("Cipher failed", e);
		}
		
		try {
			keyStore.load(null);
			SecretKey key = (SecretKey) keyStore.getKey(KEY_NAME,
					null);
			cipher.init(Cipher.ENCRYPT_MODE, key);
			return true;
		} catch (KeyPermanentlyInvalidatedException e) {
			return false;
		} catch (KeyStoreException | CertificateException | UnrecoverableKeyException | IOException | NoSuchAlgorithmException | InvalidKeyException e) {
			throw new RuntimeException("Cipher initialization failed", e);
		}
	}
}
