# // v0idengine

A lightweight game engine for 2D titles, with minimal overhead.

## Getting Started

### Installing the Engine

#### Linux
- Install dependencies

| Distribution | Package Manager | Required Packages |
|---|---|---|
| Arch         | `pacman`        | `git` `cmake` `base-devel` `sfml` `doxygen` |
| Debian       | `apt`           | `git` `cmake` `build-essential` `libsfml-dev` `doxygen` |
| Fedora*      | `dnf`           | `git-all` `cmake` `sfml-dev` `doxygen` |
| Red Hat**    | `rpm`           | `git` `cmake` `sfml-dev` `doxygen` |

`*` — On Fedora, the following command must be executed:
```bash
dnf group install "C Development Tools and Libraries" "Development Tools"
```
`**` — On Red Hat, the following command must be executed:
```bash
yum groupinstall "Development Tools" 
```

- Clone `v0idengine`
```bash
git clone https://github.com/v0idzdev/v0idengine
cd v0idengine/
```

- Build and install `v0idengine`
```bash
cmake .
make install
```

#### Windows 10/11
Windows installation instructions will be added in future.

### Creating a new Game

- Clone `v0idengine-template`
```bash
git clone https://github.com/v0idzdev/v0idengine-template
```

- Rename it to the name of your game — e.g., `MyGame`
```bash
mv v0idengine-template MyGame
```

- Enter the game directory
```bash
cd MyGame
```

#### Creating a Project Generation Script
You can write a shell script to automatically generate `v0idengine` projects.

- Create a file called `v0idengine-new` and add the commands
```bash
echo "#!/bin/sh
git clone https://github.com/v0idzdev/v0idengine-template
mv v0idengine-template '$1'" > v0idengine-new
```

- Create a scripts directory and add the file to it
```bash
mkdir -p ~/bin
mv v0idengine-new ~/bin/
```

- Allow the file to be executed
```bash
cd ~/bin
chmod +x v0idengine-new
```

- Add the file to your path
```bash
echo 'export PATH=$PATH:~/bin' > ~/.bashrc
. ~/.bashrc
```

To create a project, execute the script and pass the project name as a parameter.
- Execute `v0idengine-new`
```bash
v0idengine-new MyGame
cd MyGame
```

### Building and Running the Game

#### Linux

- Build the game
```bash
cmake .
make
```

- Run* the game
```bash
./Game
```

`*` — On some Linux distributions such as Ubuntu, the directory in which the v0idengine library is located (`/usr/local/lib/`) is not a default path. Execute the command below and run the game again:
```bash
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/usr/local/lib"
```

Alternatively, you may add the above line to your `.bashrc` so that you do not have to execute it each time you want to run your game.
```bash
echo 'export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/usr/local/lib"' > ~/.bashrc
```

#### Windows 10/11
Windows build and execution instructions will be added in future.

### Building the Documentation
- Run `doxygen` to re-generate the documentation
```
doxygen
```
