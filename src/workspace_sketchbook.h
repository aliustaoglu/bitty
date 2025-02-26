/*
** Bitty
**
** An itty bitty game engine.
**
** Copyright (C) 2020 - 2021 Tony Wang, all rights reserved
**
** For the latest info, see https://github.com/paladin-t/bitty/
*/

#ifndef __WORKSPACE_SKETCHBOOK_H__
#define __WORKSPACE_SKETCHBOOK_H__

#include "workspace.h"

/*
** {===========================================================================
** Sketchbook workspace
**
** @note Specialized workspace.
*/

class WorkspaceSketchbook : public Workspace {
public:
	struct SketchbookSettings : public Settings {
		SketchbookSettings();
		SketchbookSettings(const SketchbookSettings &other) = delete;

		SketchbookSettings &operator = (const SketchbookSettings &other);

		bool operator != (const SketchbookSettings &other) const;
	};

private:
	bool _opened = false;

	SketchbookSettings _settings;

	class ThemeSketchbook* _theme = nullptr;

	class Loader* _loader = nullptr;

public:
	WorkspaceSketchbook();
	virtual ~WorkspaceSketchbook() override;

	virtual bool open(class Window* wnd, class Renderer* rnd, const class Project* project, Executable* exec, class Primitives* primitives, const Text::Dictionary &options) override;
	virtual bool close(class Window* wnd, class Renderer* rnd, const class Project* project, Executable* exec) override;

	virtual const Settings* settings(void) const override;
	virtual Settings* settings(void) override;
	virtual class Theme* theme(void) const override;

	virtual bool load(class Window* wnd, class Renderer* rnd, const class Project* project, class Primitives* primitives) override;
	virtual bool save(class Window* wnd, class Renderer* rnd, const class Project* project, class Primitives* primitives) override;

	virtual unsigned update(class Window* wnd, class Renderer* rnd, const class Project* project, Executable* exec, class Primitives* primitives, double delta, unsigned fps, bool alive, bool* indicated) override;

	virtual void require(Executable* exec) override;

	virtual void focusGained(class Window* wnd, class Renderer* rnd, const class Project* project, Executable* exec, class Primitives* primitives) override;
	virtual void focusLost(class Window* wnd, class Renderer* rnd, const class Project* project, Executable* exec, class Primitives* primitives) override;

	virtual void renderTargetsReset(class Window* wnd, class Renderer* rnd, const class Project* project, Executable* exec, class Primitives* primitives) override;

protected:
	using Workspace::load;
	using Workspace::save;

private:
	void shortcuts(class Window* wnd, class Renderer* rnd, const class Project* project, Executable* exec, class Primitives* primitives);
	void menu(class Window* wnd, class Renderer* rnd, const class Project* project, Executable* exec, class Primitives* primitives);

	void loadProject(class Window* wnd, class Renderer* rnd, const class Project* project, Executable* exec, class Primitives* primitives, const Text::Dictionary &options);
	void unloadProject(const class Project* project, Executable* exec);

	void showPreferences(class Window* wnd, class Renderer* rnd, const class Project* project, class Primitives* primitives);
	void showAbout(class Window* wnd, class Renderer* rnd, class Primitives* primitives);
	void showPaused(class Window* wnd, class Renderer* rnd, const class Project* project, class Primitives* primitives);
};

/* ===========================================================================} */

#endif /* __WORKSPACE_SKETCHBOOK_H__ */
