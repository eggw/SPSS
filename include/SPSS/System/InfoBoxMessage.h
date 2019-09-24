#ifndef INFOBOXMESSAGE_H_INCLUDED
#define INFOBOXMESSAGE_H_INCLUDED

#include <SPSS/Graphics/MulticolorText.h>
#include <SPSS/Util/Message.h>

#include <SFML/Graphics.hpp>

namespace spss {

	class InfoBoxMessage : public sf::Drawable {
	  public:
		InfoBoxMessage(const Message&  _msg,
		                const sf::Font& _font,
		                unsigned int    _charSize);

		void removeNewlines(std::string& _str);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void fitWidth(float _width);

		void setString(const std::string& _str);
		void setPosition(sf::Vector2f _pos);
		void setTransparency(int _a);

		sf::Vector2f  getPosition() const;
		sf::FloatRect getGlobalBounds() const;
		sf::FloatRect getLocalBounds() const;
		int           getTransparency() const;
		unsigned int  getNumberOfLines(size_t _startPos = 0,
		                               size_t _endPos   = 0) const;

	  private:
		//Data members --------------------------------
		spss::MulticolorText m_text;
		Message              m_message;
		//---------------------------------------------
	};
} // namespace spss

#endif // INFOBOXMESSAGE_H_INCLUDED