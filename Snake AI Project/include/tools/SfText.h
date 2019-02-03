﻿#pragma once

#ifndef __SF_TEXT_H__
#define __SF_TEXT_H__

#include <SFML/Graphics/Text.hpp>

namespace Tools
{
	enum class ETextEncrage
	{
		UpLeft,
		UpRight,
		DownLeft,
		DownRight,
		Middle
	};

	struct SfText
	{
	public:
		SfText();
		SfText(int p_size, sf::Font p_font, sf::Color p_color, sf::Vector2f p_position, std::string p_text);
		~SfText();

		void SetSize(int p_size);
		void SetFont(sf::Font& p_font);
		void SetColor(sf::Color p_color);
		void SetPosition(sf::Vector2f p_position);
		void SetOrigin(ETextEncrage p_textEncrage);

		template<typename P1, typename ... Param>
		void SetText(const P1 &p1, const Param& ... param)
		{
			STRING = "";

			ParamToString(p1, param...);

			TEXT.setString(STRING);
		}

		const int& GetSize();
		const sf::Font& GetFont();
		const sf::Color& GetColor();
		const sf::Vector2f& GetPosition();
		const sf::Text& GetText();

		const sf::FloatRect& GetBounds();

	private:
		void ParamToString() {}

		template<typename P1, typename ... Param>
		void ParamToString(const P1 &p1, const Param& ... param)
		{
			std::stringstream ss;
			ss << p1;
			STRING += ss.str();

			ParamToString(param...);
		}

	private:

		sf::Text TEXT;
		sf::Font FONT;
		std::string STRING;
		ETextEncrage TEXT_ENCRAGE;
	};
}

#endif