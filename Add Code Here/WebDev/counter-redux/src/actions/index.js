export const inc = (num) => {
    return {
        type: "INCREMENT",
        payload: num
    }
}

export const dec = () => {
    return {
        type : "DECREMENT"
    }
}