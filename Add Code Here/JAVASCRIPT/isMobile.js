export const isMobile = {
  Android: function android() {
    return navigator.userAgent.match(/Android/i)
  },
  BlackBerry: function lackBerry() {
    return navigator.userAgent.match(/BlackBerry/i)
  },
  iOS: function iOs() {
    return navigator.userAgent.match(/iPhone|iPad|iPod/i)
  },
  Opera: function opera() {
    return navigator.userAgent.match(/Opera Mini/i)
  },
  Windows: function windows() {
    return navigator.userAgent.match(/IEMobile/i) || navigator.userAgent.match(/WPDesktop/i)
  },
  any: function any() {
    return (isMobile.Android() || isMobile.BlackBerry() || isMobile.iOS() || isMobile.Opera() || isMobile.Windows())
  }
}