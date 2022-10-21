
/**
 * @author advance
 * github profile : https://github.com/Saurabh1999
 */
package game;


import java.io.*;
import java.net.URL;
import javax.sound.sampled.*;
 

public enum SoundEffect {
    
   WINNING("sounds/win.wav"),
   START("sounds/start.wav"),
   WARNING("sounds/warn.wav"),
   HELP("sounds/help.wav"),
   LOSING("sounds/lose.wav"),
   CLICK("sounds/click.wav"),
   BUTTONCLICK("sounds/buttonclick.wav"),
   DRAW("sounds/draw.wav");
   
   
   // Nested class for specifying volume
   public static enum Volume {
      MUTE, LOW, MEDIUM, HIGH
   }
   
   public static Volume volume = Volume.LOW;
   
   // Each sound effect has its own clip, loaded with its own sound file.
   private Clip clip;
   
   // Constructor to construct each element of the enum with its own sound file.
   SoundEffect(String soundFileName) {
      try {
         // Use URL (instead of File) to read from disk and JAR.
         URL url = this.getClass().getClassLoader().getResource(soundFileName);
         // Set up an audio input stream piped from the sound file.
         AudioInputStream audioInputStream = AudioSystem.getAudioInputStream(url);
         // Get a clip resource.
         clip = AudioSystem.getClip();
         // Open audio clip and load samples from the audio input stream.
         clip.open(audioInputStream);
      } catch (UnsupportedAudioFileException e) {
         e.printStackTrace();
      } catch (IOException e) {
         e.printStackTrace();
      } catch (LineUnavailableException e) {
         e.printStackTrace();
      }
   }
   
   // Play or Re-play the sound effect from the beginning, by rewinding.
   public void play() {
      if (volume != Volume.MUTE) {
         if (clip.isRunning())
            clip.stop();   // Stop the player if it is still running
         clip.setFramePosition(0); // rewind to the beginning
         clip.start();     // Start playing
      }
   }
   
   public void stop(){
       if (clip.isRunning())
            clip.stop();
       clip.setFramePosition(0);
   }
   
   // Optional static method to pre-load all the sound files.
   static void init() {
      values(); // calls the constructor for all the elements
   }
}