class Carousel {

    timer = null
    duration = 3000
    /**
     * @type {HTMLElement}
     */
    root
    autoStart = true
    currentIndex = 0
    #numberItem = 0
    #widthItem
    #dotEls = []
    onUpdate
  
    constructor(element, options = {}) {
      if(!element && !element instanceof HTMLElement) throw new Error("Root element is invalid")
      this.root = element
      this.#numberItem = this.root.querySelectorAll(".carousel-item").length
      this.#widthItem = this.root.clientWidth
      if(options.duration) this.duration = options.duration
      if(options.autoStart) this.autoStart = options.autoStart
      if(options.onUpdate) this.onUpdate = options.onUpdate
      this.#addDots()
      if(this.autoStart) this.start()
    }
  
    #addDots() {
      const dotContainer = document.createElement("div")
      dotContainer.classList.add("carousel-control")
  
      for (let i = 0; i < this.#numberItem; i++) {
        const dotElement = document.createElement("div")
        dotElement.classList.add("carousel-control-dot")
        if(this.currentIndex === i) dotElement.classList.add("active")
        dotElement.addEventListener("click", () => {
          this.goto(i)
        })
        this.#dotEls.push(dotElement)
        dotContainer.appendChild(dotElement)
      }
  
      this.root.appendChild(dotContainer)
    }
    
    start() {
      if(this.timer) clearInterval(this.timer)
      this.timer = setInterval(() => {
        this.next()
      }, 3000);
    }
  
    stop() {
      clearInterval(this.timer)
    }
  
    update() {
      const width = this.#widthItem
      this.root.querySelector(".carousel").style.transform = `translateX(-${this.currentIndex * width}px)`
      if(this.onUpdate && this.onUpdate.constructor === Function) this.onUpdate(this.currentIndex)
      this.#dotEls.forEach((el, i) => {
        if(i === this.currentIndex) el.classList.add("active")
        else el.classList.remove("active")
      });
    }
  
    goto(index) {
      this.currentIndex = index
      this.update()
      this.stop()
      if(this.autoStart) this.start()
    }
  
    next() {
      if(this.currentIndex >= this.#numberItem - 1) this.reset()
      else this.currentIndex++
      this.update()
    }
  
    prev() {
      if(this.currentIndex === 0) this.currentIndex === this.#numberItem
      else this.currentIndex--
      this.update()
    }
  
    current() {
      return this.currentIndex
    }
   
    reset() {
      this.currentIndex = 0;
      this.update()
    }
  
    destroy() {
      // Handle destroy here
      clearInterval(this.timer)
      this.timer = null
    }
  }