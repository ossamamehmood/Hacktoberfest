"what to use underline for?

set background=dark
hi clear
if exists("syntax_on")
  syntax reset
endif
let g:colors_name="avrabecz"
hi  Normal      ctermfg=gray ctermbg=black guifg=gray guibg=black
hi  Comment     ctermfg=darkgrey cterm=italic guifg=darkgrey gui=italic
hi  Todo        ctermfg=darkgrey ctermbg=red guifg=darkgrey guibg=red
hi  Number      ctermfg=darkgreen guifg=darkgreen
hi  SpecialChar ctermfg=green cterm=italic guifg=green gui=bold,italic
hi  kGroup3Digits ctermfg=green cterm=bold guifg=green gui=bold
hi  String      ctermfg=darkyellow guifg=darkyellow
hi  Conditional ctermfg=cyan cterm=bold guifg=cyan gui=bold
hi  link Repeat Conditional
hi  Statement   ctermfg=blue cterm=bold guifg=blue gui=bold
hi  Function    ctermfg=darkred guifg=darkred
hi  Type        ctermfg=magenta cterm=bold guifg=magenta gui=bold
hi  Operator    ctermfg=red cterm=bold guifg=red gui=bold
hi  Identifier  ctermfg=yellow cterm=bold guifg=yellow gui=bold

hi  link Character String
hi  kStringSpecial ctermfg=yellow cterm=italic guifg=yellow gui=bold,italic

hi  kSymbol     ctermfg=darkmagenta guifg=darkmagenta
hi  kNullSymbol ctermfg=magenta cterm=bold guifg=magenta gui=bold
hi  qSymbol     ctermfg=darkmagenta guifg=darkmagenta
hi  kHandle     ctermfg=darkcyan guifg=darkcyan
hi  qHandle     ctermfg=darkcyan guifg=darkcyan
hi  kAdverb     ctermfg=yellow cterm=bold guifg=yellow gui=bold
hi  qAdverb     ctermfg=yellow cterm=bold guifg=yellow gui=bold
hi  qVerb       ctermfg=red cterm=bold guifg=red gui=bold
hi  kDotQ       ctermfg=darkblue guifg=darkblue
"hi  kAssign     ctermbg=blue guifg=white gui=bold

hi  qAssign     ctermbg=darkgrey ctermfg=gray
hi  qAssignPublic ctermbg=darkgrey cterm=bold ctermfg=white
hi  qAssignParameter ctermbg=darkgrey cterm=italic ctermfg=darkcyan

hi  kqPublic     ctermfg=white cterm=bold guifg=white gui=bold
hi  kPlaceholder ctermfg=darkcyan cterm=italic guifg=darkcyan gui=italic
hi  kqParameter  ctermfg=darkcyan cterm=italic guifg=darkcyan gui=italic
