"--------------------------------------------------------------------------------------------------

" Vim syntax file
" Language: Temizer Image Description
" Maintainer: Selim Temizer
" Latest Revision: 18 May 2018

"--------------------------------------------------------------------------------------------------

if exists("b:current_syntax")
  finish
endif

"--------------------------------------------------------------------------------------------------

syn match   tidComment         '^\s*#.*$' contains=tidTodo

syn keyword tidTodo            TODO NOTE  contained

syn keyword tidStatement       Image      nextgroup=tidImageWidth      skipwhite
syn match   tidImageWidth      '\d\+'     nextgroup=tidImageHeight     skipwhite contained
syn match   tidImageHeight     '\d\+'     nextgroup=tidFilename        skipwhite contained
syn match   tidFilename        '\S\+'     display                                contained

syn keyword tidStatement       SetColor   nextgroup=tidRed             skipwhite
syn match   tidRed             '\d\+'     nextgroup=tidGreen           skipwhite contained
syn match   tidGreen           '\d\+'     nextgroup=tidBlue            skipwhite contained
syn match   tidBlue            '\d\+'     display                                contained

syn keyword tidStatement       Clear

syn keyword tidStatement       Point      nextgroup=tidPointRow        skipwhite
syn match   tidPointRow        '\d\+'     nextgroup=tidPointCol        skipwhite contained
syn match   tidPointCol        '\d\+'     display                                contained

syn keyword tidStatement       Line       nextgroup=tidLineFromRow     skipwhite
syn match   tidLineFromRow     '\d\+'     nextgroup=tidLineFromCol     skipwhite contained
syn match   tidLineFromCol     '\d\+'     nextgroup=tidLineToRow       skipwhite contained
syn match   tidLineToRow       '\d\+'     nextgroup=tidLineToCol       skipwhite contained
syn match   tidLineToCol       '\d\+'     display                                contained

syn keyword tidStatement       Arc        nextgroup=tidArcRow          skipwhite
syn match   tidArcRow          '\d\+'     nextgroup=tidArcCol          skipwhite contained
syn match   tidArcCol          '\d\+'     nextgroup=tidArcStartAngle   skipwhite contained
syn match   tidArcStartAngle   '\d\+'     nextgroup=tidArcEndAngle     skipwhite contained
syn match   tidArcEndAngle     '\d\+'     nextgroup=tidArcRadius       skipwhite contained
syn match   tidArcRadius       '\d\+'     nextgroup=tidArcSegments     skipwhite contained
syn match   tidArcSegments     '\d\+'     display                                contained

syn keyword tidStatement       Rectangle  nextgroup=tidRectangleRow    skipwhite
syn match   tidRectangleRow    '\d\+'     nextgroup=tidRectangleCol    skipwhite contained
syn match   tidRectangleCol    '\d\+'     nextgroup=tidRectangleWidth  skipwhite contained
syn match   tidRectangleWidth  '\d\+'     nextgroup=tidRectangleHeight skipwhite contained
syn match   tidRectangleHeight '\d\+'     display                                contained

syn keyword tidStatement       Polygon    nextgroup=tidPolygonRow      skipwhite
syn match   tidPolygonRow      '\d\+'     nextgroup=tidPolygonCol      skipwhite contained
syn match   tidPolygonCol      '\d\+'     nextgroup=tidPolygonRadius   skipwhite contained
syn match   tidPolygonRadius   '\d\+'     nextgroup=tidPolygonSides    skipwhite contained
syn match   tidPolygonSides    '\d\+'     display                                contained

syn keyword tidStatement       Fill       nextgroup=tidFillRow         skipwhite
syn match   tidFillRow         '\d\+'     nextgroup=tidFillCol         skipwhite contained
syn match   tidFillCol         '\d\+'     display                                contained

syn keyword tidStatement       Print      nextgroup=tidPrintRow        skipwhite
syn match   tidPrintRow        '\d\+'     nextgroup=tidPrintCol        skipwhite contained
syn match   tidPrintCol        '\d\+'     nextgroup=tidString          skipwhite contained
syn match   tidString          '\S.*'     display                                contained

"--------------------------------------------------------------------------------------------------

let b:current_syntax = "tid"

"--------------------------------------------------------------------------------------------------

" Xterm colors - Cheat Sheet:  https://jonasjacek.github.io/colors/

highlight tidFilename ctermfg=214 guifg=#ffaf00 cterm=underline gui=underline
highlight tidString   ctermfg=177 guifg=#d787ff

highlight tidRed      ctermfg=160 guifg=#d70000
highlight tidGreen    ctermfg=40  guifg=#00d700
highlight tidBlue     ctermfg=111 guifg=#87afff

highlight tidRow      ctermfg=45  guifg=#00d7ff cterm=underline gui=underline
highlight tidCol      ctermfg=166 guifg=#d75f00

highlight tidWidth    ctermfg=32  guifg=#0087d7 cterm=reverse   gui=reverse
highlight tidHeight   ctermfg=227 guifg=#ffff5f cterm=reverse   gui=reverse

highlight tidAngle    ctermfg=50  guifg=#00ffd7 cterm=reverse   gui=reverse
highlight tidRadius   ctermfg=13  guifg=#ff00ff
highlight tidCount    ctermfg=94  guifg=#875f00 cterm=underline gui=underline

"--------------------------------------------------------------------------------------------------

hi def link        tidPointRow tidRow
hi def link     tidLineFromRow tidRow
hi def link       tidLineToRow tidRow
hi def link          tidArcRow tidRow
hi def link    tidRectangleRow tidRow
hi def link      tidPolygonRow tidRow
hi def link         tidFillRow tidRow
hi def link        tidPrintRow tidRow

hi def link        tidPointCol tidCol
hi def link     tidLineFromCol tidCol
hi def link       tidLineToCol tidCol
hi def link          tidArcCol tidCol
hi def link    tidRectangleCol tidCol
hi def link      tidPolygonCol tidCol
hi def link         tidFillCol tidCol
hi def link        tidPrintCol tidCol

hi def link      tidImageWidth tidWidth
hi def link  tidRectangleWidth tidWidth

hi def link     tidImageHeight tidHeight
hi def link tidRectangleHeight tidHeight

hi def link   tidArcStartAngle tidAngle
hi def link     tidArcEndAngle tidAngle

hi def link       tidArcRadius tidRadius
hi def link   tidPolygonRadius tidRadius

hi def link     tidArcSegments tidCount
hi def link    tidPolygonSides tidCount

"--------------------------------------------------------------------------------------------------

hi def link tidTodo            Todo
hi def link tidComment         Comment
hi def link tidStatement       Statement

" Some Possible Choices:
"-----------------------
" Comment     // Blue
" PreProc     // Purple
" Type        // Green
" Constant    // Red
" Statement   // Yellow
" Identifier  // Cyan
" Special     // Orange
" Underlined  // Blue, underlined
" Todo        // Yellow background
" Error       // Dark Red
" Ignore      // (Invisible)

"--------------------------------------------------------------------------------------------------
