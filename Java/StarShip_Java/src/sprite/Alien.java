package sprite;

import javax.swing.ImageIcon;

public class Alien extends Sprite{
	
	private Bomb bomb;
	
	public Alien(int x, int y) {
		
		initAlien(x, y);
	}
	
	private void initAlien(int x, int y) {
		
		this.x = x;
		this.y = y;
		
		bomb = new Bomb(x,y);
		
		var alienImg = "src/images/alien.png";
		var img = new ImageIcon(alienImg);
		
		setImage(img.getImage());
	}
	
	public void act(int direction) {
		
		this.x += direction;
	}
	
	public Bomb getBomb() {
		return bomb;
	}
	
	public class Bomb extends Sprite {
		
		private boolean destroyed;
		
		public Bomb(int x, int y) {
			
			initBomb(x, y);
		}
		
		private void initBomb(int x, int y) {
			
			setDestroyed(true);
			
			this.x = x;
			this.y = y;
			
			var bombImg = "src/images/bomb.png";
			var img = new ImageIcon(bombImg);
			setImage(img.getImage());
		}
		
        public void setDestroyed(boolean destroyed) {

            this.destroyed = destroyed;
        }

        public boolean isDestroyed() {

            return destroyed;
        }
		
	}

}
