// function getKey (e) {
//     var location = e.location;
//     var selector;
//     if (location === KeyboardEvent.DOM_KEY_LOCATION_RIGHT) {
//         selector = ['[data-key="' + e.keyCode + '-R"]']
//     } else {
//         var code = e.keyCode || e.which;
//         selector = [
//             '[data-key="' + code + '"]',
//             '[data-char*="' + encodeURIComponent(String.fromCharCode(code)) + '"]'
//         ].join(',');
//     }
//     return document.querySelector(selector);
// }

// function pressKey (char) {
//     var key = document.querySelector('[data-char*="' + char.toUpperCase() + '"]');
//     if (!key) {
//         return console.warn('No key for', char);
//     }
//     key.setAttribute('data-pressed', 'on');
//     setTimeout(function () {
//         key.removeAttribute('data-pressed');
//     }, 200);
// }

// var h1 = document.querySelector('h1');
// var originalQueue = h1.innerHTML;
// var queue = h1.innerHTML;

// function next () {
//     var c = queue[0];
//     queue = queue.slice(1);
//     h1.innerHTML = originalQueue.slice(0, originalQueue.length - queue.length);
//     pressKey(c);
//     if (queue.length) {
//         setTimeout(next, Math.random() * 200 + 50);
//     }
// }

// h1.innerHTML = "&nbsp;";
// setTimeout(next, 500);

// document.body.addEventListener('keydown', function (e) {
//     var key = getKey(e);
//     if (!key) {
//         return console.warn('No key for', e.keyCode);
//     }

//     key.setAttribute('data-pressed', 'on');
// });

// document.body.addEventListener('keyup', function (e) {
//     var key = getKey(e);
//     key && key.removeAttribute('data-pressed');
// });

// function size () {
//     var size = keyboard.parentNode.clientWidth / 90;
//     keyboard.style.fontSize = size + 'px';
//     console.log(size);
// }

// var keyboard = document.querySelector('.keyboard');
// window.addEventListener('resize', function (e) {
//     size();
// });
// size();

document.addEventListener("keypress",function(event)
{

    console.log(event);
    switch(event.key)
    {
        case event.key="a":
        {
            const audio = new Audio("Resource/Guitar/2.mp3");
            console.log(audio);
            audio.play();
            break;
        }
        case event.key="s":
        {
            const audio = new Audio("Resource/sounds/1.mp3");
            console.log(audio);
            audio.play();
            break;
        }
        case event.key="d":
        {
            const audio = new Audio("Resource/Guitar/4.mp3");
            console.log(audio);
            audio.play();
            break;
        }
        case event.key="f":
        {
            const audio = new Audio("Resource/Guitar/5.mp3");
            console.log(audio);
            audio.play();
            break;
        }
        case event.key="g":
        {
            const audio = new Audio("Resource/Guitar/6.mp3");
            console.log(audio);
            audio.play();
            break;
        }
        case event.key="h":
        {
            const audio = new Audio("Resource/Guitar/7.mp3");
            console.log(audio);
            audio.play();
            break;
        }
        case event.key="i":
        {
            const audio = new Audio("Resource/Guitar/8.mp3");
            console.log(audio);
            audio.play();
            break;
        }
        case event.key="j":
        {
            const audio = new Audio("Resource/Guitar/9.mp3");
            console.log(audio);
            audio.play();
            break;
        }
        case event.key="k":
        {
            const audio = new Audio("Resource/Guitar/10.mp3");
            console.log(audio);
            audio.play();
            break;
        }
        case event.key="u":
        {
            const audio = new Audio("Resource/Flute/1.mp3");
            console.log(audio);
            audio.play();
            break;
        }
        case event.key="r":
        {
            const audio = new Audio("Resource/Flute/2.mp3");
            console.log(audio);
            audio.play();
            break;
        }
        case event.key="e":
        {
            const audio = new Audio("Resource/Drum/1.mp3");
            console.log(audio);
            audio.play();
            break;
        }
        case event.key="i":
        {
            const audio = new Audio("Resource/Drum/2.mp3");
            console.log(audio);
            audio.play();
            break;
        }
        case event.key="w":
        {
            const audio = new Audio("Resource/Drum/3.mp3");
            console.log(audio);
            audio.play();
            break;
        }
        case event.key="w":
        {
            const audio = new Audio("Resource/Drum/4.mp3");
            console.log(audio);
            audio.play();
            break;
        }

        
            



 
    }
        





    }
)