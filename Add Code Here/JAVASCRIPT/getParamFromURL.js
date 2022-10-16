export const getParamFromURL = (param) => {
  const urlParams = new URLSearchParams(window.location.search)
  return urlParams.get(param)
}