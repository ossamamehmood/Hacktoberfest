/** @type {import('tailwindcss').Config} */
const mySafelist = [
  'drop-shadow-3xl',
  'pt-3',
  'hover:scale-125',
  'transform',
  'transition',
  'duration-500',
  'p-3',
  'px-2',
  'max-w-[224px]',
  'font-semibold',
  'justify-between',
  'mb-1',
  'text-zinc-100',
  'text-zinc-300',
  'w-28',
  'w-36',
  'h-28',
  'h-36',
  'capitalize',
  'hidden',
  'visible',
  'bg-zinc-800',
  'w-[672px]',
  'h-[600px]',
  'm-auto',
  'text-2xl'
]

for (i = 1; i <= 100; i++) {
  mySafelist.push(`w-[${i}%]`)
}

for (i = 300; i <= 700; i += 200) {
  mySafelist.push(`bg-grass-${i}`)
  mySafelist.push(`bg-poison-${i}`)
  mySafelist.push(`bg-fire-${i}`)
  mySafelist.push(`bg-flying-${i}`)
  mySafelist.push(`bg-water-${i}`)
  mySafelist.push(`bg-bug-${i}`)
  mySafelist.push(`bg-normal-${i}`)
  mySafelist.push(`bg-electric-${i}`)
  mySafelist.push(`bg-ground-${i}`)
  mySafelist.push(`bg-fairy-${i}`)
  mySafelist.push(`bg-fighting-${i}`)
  mySafelist.push(`bg-psychic-${i}`)
  mySafelist.push(`bg-rock-${i}`)
  mySafelist.push(`bg-ice-${i}`)
  mySafelist.push(`bg-ghost-${i}`)
  mySafelist.push(`bg-dragon-${i}`)
  mySafelist.push(`bg-dark-${i}`)
  mySafelist.push(`bg-steel-${i}`)
  mySafelist.push(`bg-shadow-${i}`)
  mySafelist.push(`bg-unknown-${i}`)
  mySafelist.push(`text-grass-${i}`)
  mySafelist.push(`text-poison-${i}`)
  mySafelist.push(`text-fire-${i}`)
  mySafelist.push(`text-flying-${i}`)
  mySafelist.push(`text-water-${i}`)
  mySafelist.push(`text-bug-${i}`)
  mySafelist.push(`text-normal-${i}`)
  mySafelist.push(`text-electric-${i}`)
  mySafelist.push(`text-ground-${i}`)
  mySafelist.push(`text-fairy-${i}`)
  mySafelist.push(`text-fighting-${i}`)
  mySafelist.push(`text-psychic-${i}`)
  mySafelist.push(`text-rock-${i}`)
  mySafelist.push(`text-ice-${i}`)
  mySafelist.push(`text-ghost-${i}`)
  mySafelist.push(`text-dragon-${i}`)
  mySafelist.push(`text-dark-${i}`)
  mySafelist.push(`text-steel-${i}`)
  mySafelist.push(`text-shadow-${i}`)
  mySafelist.push(`text-unknown-${i}`)
}


module.exports = {
  content: ['./**/*.{html, js}'],
  safelist: mySafelist,
  mode: 'jit',
  theme: {
    extend: {
      dropShadow: {
        '3xl': '10px 10px 200px #159F6E',
      },
      gridTemplateRows: {
        'pokemonBody': '100px minmax(850px, 1fr) 100px'
      },
      fontFamily: {
        sans: ["Roboto", "sans-serif"],
      },
      backgroundImage: {
        'pokemon': "url('/assets/images/pokebola.png')",
      },
      colors: {
        'grass-300' : '#60e1ca',
        'grass-500' : '#159F6E',
        'grass-800': '#063c28',
        'fire-300': '#fd8585',
        'fire-500': '#fb6c6c',
        'fire-800': '#f51e1e',
        'water-300': '#b3dafd',
        'water-500': '#14baec',
        'water-800': '#096e8c',
        'electric-300': '#fdde8a',
        'electric-500': '#fcc951',
        'electric-800': '#f9b500',
        'ground-300': '#e2be84',
        'ground-500': '#c37b45',
        'ground-800': '#8a4b00',
        'rock-300': '#debecf',
        'rock-500': '#b77388',
        'rock-800': '#7a2f4d',
        'fairy-300': '#f4b4e1',
        'fairy-500': '#ec75bc',
        'fairy-800': '#c4007d',
        'dragon-300': '#f5cce6',
        'dragon-500': '#ea7cb1',
        'dragon-800': '#b3006e',
        'bug-300': '#bed580',
        'bug-500': '#699932',
        'bug-800': '#2e5a00',
        'ghost-300': '#d1caf5',
        'ghost-500': '#9970aa',
        'ghost-800': '#4d2e5a',
        'dark-300': '#c5bcb8',
        'dark-500': '#73675d',
        'dark-800': '#3a3a3a',
        'steel-300': '#adc4db',
        'steel-500': '#6b89a6',
        'steel-800': '#2e3f4f',
        'ice-300': '#edfeff',
        'ice-500': '#a8d8d8',
        'ice-800': '#4f5f5f',
        'normal-300': '#c5c5c5',
        'normal-500': '#b8b8b8',
        'normal-800': '#5f5f5f',
        'fighting-300': '#ffb36d',
        'fighting-500': '#e36747',
        'fighting-800': '#a33f00',
        'psychic-300': '#8c7379',
        'psychic-500': '#473041',
        'psychic-800': '#1e0f10',
        'poison-300': '#bd93ed',
        'poison-500': '#a86bca',
        'poison-800': '#5a2a8a',
        'flying-300': '#b54c7a',
        'flying-500': '#ff2cca',
        'flying-800': '#a3007a',
        'unknown-300': '#c7b5de',
        'unknown-500': '#8f70b1',
        'unknown-800': '#4f2e5a',
        'shadow-300': '#b3b3b3',
        'shadow-500': '#737373',
        'shadow-800': '#3a3a3a',
      }
    },
  },
  plugins: [
],
}
