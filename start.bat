node-gyp configure
node-gyp build
node-gyp rebuild --target=0.34.1 --arch=x64 --dist-url=https://atom.io/download/atom-shell
npm start