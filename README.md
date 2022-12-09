<!DOCTYPE html>
<html>

<body class="stackedit">
  <div class="stackedit__html"><h1 id="simple-shell-for-holberton-school">Simple Shell for Holberton School</h1>
<p>This project consists of creating a simple Shell based on the Bourne Shell.</p>
<h2 id="description">Description</h2>
<p>A more limited recreation of the Bourne Shell.<br>
It’s a UNIX command line interpreter which displays a prompt and waits for the user to type a command. The prompt is displayed again each time a command has been executed and the command lines are simple, no semicolons, no pipes, no redirections or any other advanced features. It handles commands with arguments, the PATH and “exit” as a built-in that exits the shell. If an executable cannot be found, prints an error message and displays the prompt again.</p>
<h2 id="compilation">Compilation</h2>
<pre><code>gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
</code></pre>
<h2 id="requirements">Requirements</h2>
<h3 id="general">General</h3>
<ul>
<li>Allowed editors:  <code>vi</code>,  <code>vim</code>,  <code>emacs</code></li>
<li>All your files will be compiled on Ubuntu 20.04 LTS using  <code>gcc</code>, using the options  <code>-Wall -Werror -Wextra -pedantic -std=gnu89</code></li>
<li>All your files should end with a new line</li>
<li>A  <code>README.md</code>  file, at the root of the folder of the project is mandatory</li>
<li>Your code should use the  <code>Betty</code>  style. It will be checked using  <a href="https://github.com/holbertonschool/Betty/blob/master/betty-style.pl" title="betty-style.pl">betty-style.pl</a>  and  <a href="https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl" title="betty-doc.pl">betty-doc.pl</a></li>
<li>Your shell should not have any memory leaks</li>
<li>No more than 5 functions per file</li>
<li>All your header files should be include guarded</li>
<li>Use system calls only when you need to<br>
All your files and folders are presented as a tree in the file explorer. You can switch from one to another by clicking a file in the tree.</li>
</ul>
<h2 id="examples">Examples</h2>
<p>We’re gonna show how to list all files in the current directory in long format, in non-interactive mode and in interactive mode.</p>
<p><strong>Non-interactive mode:</strong></p>
<pre><code># echo ls -l | ./hsh
total 48
-rw-r--r-- 1 root root   260 Dec  7 09:50 AUTHORS
-rw-r--r-- 1 root root  3232 Dec  7 09:19 auxiliar_functions.c
-rwxr-xr-x 1 root root 17864 Dec  9 04:47 hsh
-rw-r--r-- 1 root root   682 Dec  7 09:15 main.h
-rw-r--r-- 1 root root  2613 Dec  8 13:01 man_1_simple_shell
-rw-r--r-- 1 root root    30 Dec  5 08:11 README.md
-rw-r--r-- 1 root root  1161 Dec  9 04:47 simpleshell.c
-rw-r--r-- 1 root root  2267 Dec  5 06:53 string_functions.c
</code></pre>
<p><strong>Interactive mode:</strong></p>
<pre><code>\# ./hsh
$ ls -l
total 48
-rw-r--r-- 1 root root   260 Dec  7 09:50 AUTHORS
-rw-r--r-- 1 root root  3232 Dec  7 09:19 auxiliar_functions.c
-rwxr-xr-x 1 root root 17864 Dec  9 04:47 hsh
-rw-r--r-- 1 root root   682 Dec  7 09:15 main.h
-rw-r--r-- 1 root root  2613 Dec  8 13:01 man_1_simple_shell
-rw-r--r-- 1 root root    30 Dec  5 08:11 README.md
-rw-r--r-- 1 root root  1161 Dec  9 04:47 simpleshell.c
-rw-r--r-- 1 root root  2267 Dec  5 06:53 string_functions.c
</code></pre>
<h2 id="testing">Testing</h2>
<pre><code># ./hsh
$ ls
AUTHORS  auxiliar_functions.c  hsh  Lucas  main.h  man_1_simple_shell  README.md  simpleshell.c  string_functions.c
$ ls -l
total 52
-rw-r--r-- 1 root root   260 Dec  7 09:50 AUTHORS
-rw-r--r-- 1 root root  3232 Dec  7 09:19 auxiliar_functions.c
-rwxr-xr-x 1 root root 17864 Dec  9 04:47 hsh
-rw-r--r-- 1 root root     5 Dec  9 05:17 Lucas
-rw-r--r-- 1 root root   682 Dec  7 09:15 main.h
-rw-r--r-- 1 root root  2613 Dec  8 13:01 man_1_simple_shell
-rw-r--r-- 1 root root    30 Dec  5 08:11 README.md
-rw-r--r-- 1 root root  1161 Dec  9 04:47 simpleshell.c
-rw-r--r-- 1 root root  2267 Dec  5 06:53 string_functions.c
$ Hello World
./hsh: 3: Hello: not found
$ env
HOSTNAME=de813e2873d6
LANGUAGE=en_US:en
PWD=/holbertonschool-simple_shell
TZ=America/Los_Angeles
HOME=/root
LANG=en_US.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm
LESSOPEN=| /usr/bin/lesspipe %s
SHLVL=1
LC_ALL=en_US.UTF-8
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
OLDPWD=/
_=./hsh
$                 ls             -las
total 52
 0 drwxr-xr-x 3 root root   189 Dec  9 05:17 .
 0 drwxr-xr-x 1 root root   233 Dec  5 08:11 ..
 4 -rw-r--r-- 1 root root   260 Dec  7 09:50 AUTHORS
 4 -rw-r--r-- 1 root root  3232 Dec  7 09:19 auxiliar_functions.c
 0 drwxr-xr-x 8 root root   185 Dec  7 09:38 .git
20 -rwxr-xr-x 1 root root 17864 Dec  9 04:47 hsh
 4 -rw-r--r-- 1 root root     5 Dec  9 05:17 Lucas
 4 -rw-r--r-- 1 root root   682 Dec  7 09:15 main.h
 4 -rw-r--r-- 1 root root  2613 Dec  8 13:01 man_1_simple_shell
 4 -rw-r--r-- 1 root root    30 Dec  5 08:11 README.md
 4 -rw-r--r-- 1 root root  1161 Dec  9 04:47 simpleshell.c
 4 -rw-r--r-- 1 root root  2267 Dec  5 06:53 string_functions.c
$ exit
#
</code></pre>
<h2 id="flowchart">Flowchart</h2>
<p><a href="https://freeimage.host/i/HnhiNgR"><img src="https://iili.io/HnhiNgR.md.png" alt="HnhiNgR.md.png"></a></p>
</div>
</body>

</html>
