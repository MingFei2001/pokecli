# pokecli

> 🖼️ Show a random Pokémon ASCII art in your terminal, blazingly fast.

**Pokecli** is a tiny C program that prints a random Pokémon sprite every time you run it. Perfect for ricing, dotfiles, or just adding a bit of fun to your shell. *No dependencies, just pure speed.*

- 🟢 Random Pokémon ASCII art on every run
- ⚡️ Super fast, written in C
- 🎨 Great for screenshots and showing off your setup
- 🐧 Made for Linux (Debian), but easy to adapt

## Installation

Clone, build, and run:

```bash
git clone https://github.com/MingFei2001/pokecli.git --depth=1
cd pokecli
make
./pokecli
```

## Usage

- Run `./pokecli` for a random Pokémon.
- Run `./pokecli pikachu` to summon a specific one (currently only the first 151 is available 😓)
- Drop it in your `.bashrc`, `.zshrc`, or your favorite rice script for instant joy.

## TODO

- [x] Random Pokémon by default
- [ ] Add a manpage
- [ ] Package for easy install
- [ ] Make a .deb package
- [x] Polish this README

## Contributing

I love ricing and I'm still learning C, so contributions, suggestions, and issues are super welcome! If you want to see pokecli on your distro or have ideas for new features, open an issue or PR.

## Credits

- [acxz/pokescript](https://github.com/acxz/pokescript)
- [phoneybadger/pokemon-colorscripts](https://gitlab.com/phoneybadger/pokemon-colorscripts)
- [dwt1/shell-color-scripts](https://gitlab.com/dwt1/shell-color-scripts)

## License

MIT – see [LICENSE](./LICENSE) for details.