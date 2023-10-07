const videoPlayer = document.getElementById('video-player');
const videoFileInput = document.getElementById('video-file');
const playPauseButton = document.getElementById('play-pause-button');
const volumeControl = document.getElementById('volume-control');
const progressBar = document.getElementById('progress-bar');
const videoSource = document.getElementById('video-source');

// Event listener to play/pause the video
playPauseButton.addEventListener('click', () => {
    if (videoPlayer.paused || videoPlayer.ended) {
        videoPlayer.play();
        playPauseButton.textContent = 'Pause';
    } else {
        videoPlayer.pause();
        playPauseButton.textContent = 'Play';
    }
});

// Event listener to update volume
volumeControl.addEventListener('input', () => {
    videoPlayer.volume = volumeControl.value;
});

// Event listener to update progress bar
videoPlayer.addEventListener('timeupdate', () => {
    const currentTime = videoPlayer.currentTime;
    const duration = videoPlayer.duration;
    const progress = (currentTime / duration) * 100;
    progressBar.value = progress;
});

// Event listener to seek video when progress bar is clicked
progressBar.addEventListener('click', (e) => {
    const progressBarWidth = progressBar.offsetWidth;
    const clickX = e.offsetX;
    const newTime = (clickX / progressBarWidth) * videoPlayer.duration;
    videoPlayer.currentTime = newTime;
});

// Event listener to load selected video file
videoFileInput.addEventListener('change', () => {
    const selectedFile = videoFileInput.files[0];
    if (selectedFile) {
        videoSource.src = URL.createObjectURL(selectedFile);
        videoPlayer.load();
        playPauseButton.textContent = 'Play';
    }
});
