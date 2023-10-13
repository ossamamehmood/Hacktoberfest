import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.ArrayList;
import java.util.Random;

public class SnakeGamePanel extends JPanel implements ActionListener {
    private static final int WIDTH = 300;
    private static final int HEIGHT = 300;
    private static final int UNIT_SIZE = 10;
    private static final int GAME_UNITS = (WIDTH * HEIGHT) / (UNIT_SIZE * UNIT_SIZE);
    private static final int DELAY = 75;
    private final ArrayList<Integer> snakeX = new ArrayList<>();
    private final ArrayList<Integer> snakeY = new ArrayList<>();
    private int appleX;
    private int appleY;
    private int score = 0;
    private boolean running = false;
    private char direction = 'R';
    private boolean moved = false;

    public SnakeGamePanel() {
        setPreferredSize(new Dimension(WIDTH, HEIGHT));
        setBackground(Color.black);
        setFocusable(true);
        addKeyListener(new MyKeyAdapter());
        startGame();
    }

    public void startGame() {
        snakeX.clear();
        snakeY.clear();
        snakeX.add(0);
        snakeY.add(0);
        spawnApple();
        score = 0;
        direction = 'R';
        running = true;
        moved = false;
        Timer timer = new Timer(DELAY, this);
        timer.start();
    }

    public void spawnApple() {
        Random random = new Random();
        appleX = random.nextInt(WIDTH / UNIT_SIZE) * UNIT_SIZE;
        appleY = random.nextInt(HEIGHT / UNIT_SIZE) * UNIT_SIZE;
    }

    public void move() {
        for (int i = snakeX.size() - 1; i > 0; i--) {
            snakeX.set(i, snakeX.get(i - 1));
            snakeY.set(i, snakeY.get(i - 1));
        }

        switch (direction) {
            case 'U':
                snakeY.set(0, snakeY.get(0) - UNIT_SIZE);
                break;
            case 'D':
                snakeY.set(0, snakeY.get(0) + UNIT_SIZE);
                break;
            case 'L':
                snakeX.set(0, snakeX.get(0) - UNIT_SIZE);
                break;
            case 'R':
                snakeX.set(0, snakeX.get(0) + UNIT_SIZE);
                break;
        }

        moved = true;
    }

    public void checkCollision() {
        if (snakeX.get(0) < 0 || snakeX.get(0) >= WIDTH || snakeY.get(0) < 0 || snakeY.get(0) >= HEIGHT) {
            running = false;
        }

        for (int i = 1; i < snakeX.size(); i++) {
            if (snakeX.get(i).equals(snakeX.get(0)) && snakeY.get(i).equals(snakeY.get(0))) {
                running = false;
            }
        }

        if (!running) {
            return;
        }

        if (snakeX.get(0).equals(appleX) && snakeY.get(0).equals(appleY)) {
            snakeX.add(appleX);
            snakeY.add(appleY);
            spawnApple();
            score++;
        }
    }

    public void gameOver(Graphics g) {
        String gameOverMessage = "Game Over";
        String scoreMessage = "Score: " + score;

        g.setColor(Color.red);
        g.setFont(new Font("Ink Free", Font.BOLD, 40));
        FontMetrics metrics = getFontMetrics(g.getFont());

        g.drawString(gameOverMessage, (WIDTH - metrics.stringWidth(gameOverMessage)) / 2, HEIGHT / 2 - 40);
        g.drawString(scoreMessage, (WIDTH - metrics.stringWidth(scoreMessage)) / 2, HEIGHT / 2);

        running = false;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (running) {
            move();
            checkCollision();
        }
        repaint();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        draw(g);
    }

    public void draw(Graphics g) {
        if (running) {
            g.setColor(Color.green);
            g.fillOval(appleX, appleY, UNIT_SIZE, UNIT_SIZE);

            for (int i = 0; i < snakeX.size(); i++) {
                if (i == 0) {
                    g.setColor(Color.blue);
                    g.fillRect(snakeX.get(i), snakeY.get(i), UNIT_SIZE, UNIT_SIZE);
                } else {
                    g.setColor(Color.green);
                    g.fillRect(snakeX.get(i), snakeY.get(i), UNIT_SIZE, UNIT_SIZE);
                }
            }

            g.setColor(Color.white);
            g.setFont(new Font("Ink Free", Font.BOLD, 20));
            g.drawString("Score: " + score, 10, 20);
        } else {
            gameOver(g);
        }
    }

    private class MyKeyAdapter extends KeyAdapter {
        @Override
        public void keyPressed(KeyEvent e) {
            if (e.getKeyCode() == KeyEvent.VK_LEFT && direction != 'R' && moved) {
                direction = 'L';
                moved = false;
            }
            if (e.getKeyCode() == KeyEvent.VK_RIGHT && direction != 'L' && moved) {
                direction = 'R';
                moved = false;
            }
            if (e.getKeyCode() == KeyEvent.VK_UP && direction != 'D' && moved) {
                direction = 'U';
                moved = false;
            }
            if (e.getKeyCode() == KeyEvent.VK_DOWN && direction != 'U' && moved) {
                direction = 'D';
                moved = false;
            }
        }
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Snake Game");
        SnakeGamePanel snakeGamePanel = new SnakeGamePanel();
        frame.add(snakeGamePanel);
        frame.pack();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
