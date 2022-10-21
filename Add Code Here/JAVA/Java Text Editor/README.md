# 19SW42-DSA-Project
A java text Editor
-------------------

I wanted to make a text editor using java using which we can open, modify or create new text files. So to record the information about which file is opened or what modifications have been done with a file, I needed a data structure in which I can store this kind of information.
As the text editor I am going to make has operation like undo/redo or open from history(the file(s) opened before opening of current file) options so  this is clear that no data structure other than Stack could achieve this goal in an efficient manner.
As from stack we can undo very easily by popping recent activity and same goes for redo and open from history options. For that I have provided my own implementation of stacks.
Though it has some basic functionalities to interact with text files but we can say that some how it works same as the notepad which opens/edits/creates text files.
All functionalities that were thought to be part of this project i.e text editor. are fulfilled very well. Each operation is performing actions as it should do which includes cut, copy, paste, clear, new file ,save file, undo redo and closing operations.
