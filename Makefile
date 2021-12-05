all: dot_clang editor-gtk4 editor-gtk3 editor-gtk2 editor-qml editor-qt5

dot_clang:
	pkg-config --cflags gtk4 gtk+-3.0 gtk+-2.0 Qt5Gui Qt5Quick Qt5Widgets | \
		sed -e 's@ -@\n-@g' | sort -u >.clang

editor-gtk4: editor-gtk4.c
	$(CC) -ggdb -o $@ $< `pkg-config --cflags --libs gtk4`

editor-gtk3: editor-gtk3.c
	$(CC) -ggdb -o $@ $< `pkg-config --cflags --libs gtk+-3.0`

editor-gtk2: editor-gtk2.c
	$(CC) -ggdb -o $@ $< `pkg-config --cflags --libs gtk+-2.0`

editor-qml: editor-qml.cpp
	$(CXX) -o $@ -fPIC $< `pkg-config --cflags --libs Qt5Gui Qt5Quick`

editor-qt5: editor-qt5.cpp
	$(CXX) -o $@ -fPIC $< `pkg-config --cflags --libs Qt5Gui Qt5Widgets`

clean:
	rm -f .clang editor-gtk2 editor-gtk3 editor-gtk4 editor-qml editor-qt5
