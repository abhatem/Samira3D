# Samira3D
A simple rendering engine that I'm making for educational purposes.<br/><br/>
Dependancies for now:
<ul>
<li> GLFW 3.1.2 http://www.glfw.org/
<li> GLEW 1.13.0 http://glew.sourceforge.net/
<li> GLM 0.9.6.3 http://glm.g-truc.net/0.9.6/
<li> boost 1.59.0 http://www.boost.org/ (with compiled bindaries because signals2 is used)
<li> assimp http://assimp.sourceforge.net/
<li> SOIL http://www.lonesock.net/soil.html
</ul>

cool video of a pyriamid with a texture rotating :)
https://youtu.be/dtTJRyhaxWs

Video of the same pyramid in perspective mode with ambient lighting and a pink mask (frame rate drop becomes evident when recording)
https://youtu.be/32DZLT_hqUg



Todo list for now:
<ul>
<li> Support mouse input - easy
<li> Fix a bug that causes the framerate to drop drastically (maybe do the mvp matrix calculation in another thread).
<li> Extend the material class - medium
<li> Finish the phong shading model
<li> Add macros that make the ugly template syntax, comming from boost, a bit nicer
</ul>

More at http://www.ab-hatem.com/category/samira-engine/ 
