/*
** Bitty
**
** An itty bitty game engine.
**
** Copyright (C) 2020 - 2021 Tony Wang, all rights reserved
**
** For the latest info, see https://github.com/paladin-t/bitty/
*/

#ifndef __AUDIO_H__
#define __AUDIO_H__

#include "bitty.h"
#include "text.h"
#include <array>

/*
** {===========================================================================
** Macros and constants
*/

#ifndef AUDIO_SFX_CHANNEL_COUNT
#	define AUDIO_SFX_CHANNEL_COUNT 4
#endif /* AUDIO_SFX_CHANNEL_COUNT */

/* ===========================================================================} */

/*
** {===========================================================================
** Sound
*/

/**
 * @brief Sound resource object.
 */
class Sound : public virtual Object {
public:
	typedef std::shared_ptr<Sound> Ptr;

	typedef std::function<void(void*, int)> FeedHandler;
	typedef std::function<void(void)> StopHandler;

public:
	BITTY_CLASS_TYPE('S', 'N', 'D', 'A')

	/**
	 * @param[out] len
	 */
	virtual const Byte* buffer(size_t* len /* nullable */) = 0;

	/**
	 * @param[out] len
	 */
	virtual const char* path(size_t* len /* nullable */) const = 0;
	virtual void path(const char* val, size_t len /* = 0 */) = 0;

	virtual const char* title(void) const = 0;
	virtual const char* artist(void) const = 0;
	virtual const char* album(void) const = 0;
	virtual const char* copyright(void) const = 0;

	virtual double length(void) const = 0;

	virtual double position(void) const = 0;
	virtual bool position(double pos) = 0;

	virtual bool playing(void) const = 0;
	virtual bool play(bool loop, FeedHandler feeder /* nullable */, StopHandler stopper /* nullable */) = 0;
	virtual bool paused(void) const = 0;
	virtual void pause(void) = 0;
	virtual void resume(void) = 0;
	virtual void rewind(void) = 0;
	virtual bool stop(void) = 0;
	virtual void update(void) = 0;

	virtual void clear(void) = 0;

	/**
	 * @param[out] val
	 */
	virtual bool toBytes(class Bytes* val) const = 0;
	virtual bool fromBytes(const Byte* val, size_t size) = 0;
	virtual bool fromBytes(const class Bytes* val) = 0;

	static Sound* create(void);
	static void destroy(Sound* ptr);
};

/* ===========================================================================} */

/*
** {===========================================================================
** Sfx
*/

/**
 * @brief SFX resource object.
 */
class Sfx : public virtual Object {
public:
	typedef std::shared_ptr<Sfx> Ptr;

public:
	BITTY_CLASS_TYPE('S', 'F', 'X', 'A')

	virtual int play(bool loop, const int* fadeInMs /* nullable */, int channel = -1) = 0;
	virtual bool paused(void) const = 0;
	virtual void pause(void) = 0;
	virtual void resume(void) = 0;
	virtual bool stop(const int* fadeOutMs /* nullable */) = 0;

	virtual void clear(void) = 0;

	virtual bool fromBytes(const Byte* val, size_t size) = 0;
	virtual bool fromBytes(const class Bytes* val) = 0;

	static Sfx* create(void);
	static void destroy(Sfx* ptr);
};

/* ===========================================================================} */

/*
** {===========================================================================
** Music
*/

/**
 * @brief Music resource object.
 */
class Music : public virtual Object {
public:
	typedef std::shared_ptr<Music> Ptr;

public:
	BITTY_CLASS_TYPE('M', 'U', 'S', 'A')

	virtual double length(void) const = 0;

	virtual bool play(bool loop, const int* fadeInMs /* nullable */) = 0;
	virtual bool paused(void) const = 0;
	virtual void pause(void) = 0;
	virtual void resume(void) = 0;
	virtual void rewind(void) = 0;
	virtual bool stop(const int* fadeOutMs /* nullable */) = 0;

	virtual void clear(void) = 0;

	virtual bool fromBytes(const Byte* val, size_t size) = 0;
	virtual bool fromBytes(const class Bytes* val) = 0;

	static Music* create(void);
	static void destroy(Music* ptr);
};

/* ===========================================================================} */

/*
** {===========================================================================
** Audio
*/

/**
 * @brief Audio manager.
 */
class Audio {
public:
	typedef std::array<float, AUDIO_SFX_CHANNEL_COUNT> SfxVolume;

public:
	virtual bool open(void) = 0;
	virtual bool close(void) = 0;

	virtual SfxVolume sfxVolume(void) const = 0;
	virtual void sfxVolume(const SfxVolume &vol) = 0;
	virtual void sfxVolume(float vol) = 0;

	virtual float musicVolume(void) const = 0;
	virtual void musicVolume(float vol) = 0;

	/**
	 * @param[out] paths
	 */
	virtual int soundFonts(Text::Array &paths) const = 0;
	virtual const char* soundFonts(void) const = 0;
	virtual int soundFonts(const char* paths) = 0;

	virtual void update(double delta) = 0;

	virtual void reset(void) = 0;

	static Audio* create(void);
	static void destroy(Audio* ptr);
};

/* ===========================================================================} */

#endif /* __AUDIO_H__ */
