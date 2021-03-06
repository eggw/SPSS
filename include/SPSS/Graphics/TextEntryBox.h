#pragma once

////////////////////////////////////////////////////////////////////
///
/// spss::TextEntryBox represents just that - a box in which text
/// can be entered.
///
/// It comes with all the functionality one would expect a text entry
/// box to have - including keyboard shortcuts for the most frequently
/// utilised functions (selection, skipping words, copying, pasting,
/// etc.).
///
/// The text the user types is of the customised spss::MulticolorText
/// type, which removes sf::Text's limitations of being able to only
/// set one color for the entire text object. An spss::TextEntryBox
/// object will thus automatically make text that overflows out of the
/// box transparent.
///
////////////////////////////////////////////////////////////////////

#include <SPSS/Graphics/MulticolorText.h>
#include <SFML/Graphics.hpp>

namespace spss {

	class TextEntryBox : public sf::Drawable {
	  public:
		////////////////////////////////////////////////////////////
		/// \brief Construct the text entry box
		///
		/// \param _font     Font used to draw text
		/// \param _charSize The character size
		/// \param _width    The width of the box
		/// \param _str      The default string value
		///
		////////////////////////////////////////////////////////////
		TextEntryBox(const float         _width,
		             const sf::Vector2f& _position,
		             const sf::Font&     _font,
		             const unsigned int  _charSize = 20,
		             const std::string&  _str      = "");

		////////////////////////////////////////////////////////////
		/// \brief Set the position of the text entry box
		///
		/// \param _x   The x coordinate
		/// \param _y   The y coordinate
		///
		////////////////////////////////////////////////////////////
		void setPosition(float _x, float _y);

		////////////////////////////////////////////////////////////
		/// \brief Set the position of the text entry box
		///
		/// \param _position The position
		///
		////////////////////////////////////////////////////////////
		void setPosition(const sf::Vector2f& _position);

		////////////////////////////////////////////////////////////
		/// \brief Set the color of the box
		///
		/// \param _color The color
		///
		/// \see getColor
		///
		////////////////////////////////////////////////////////////
		void setColor(const sf::Color& _color);

		////////////////////////////////////////////////////////////
		/// \brief Set the color of the caret
		///
		/// \param _color The color
		///
		/// \see getCaretColor
		///
		////////////////////////////////////////////////////////////
		void setCaretColor(const sf::Color& _color);

		////////////////////////////////////////////////////////////
		/// \brief Set the rect's outline color
		///
		/// \param _color The color
		///
		/// \see getOutlineColor
		///
		////////////////////////////////////////////////////////////
		void setOutlineColor(const sf::Color& _c);

		////////////////////////////////////////////////////////////
		/// \brief Set the rect's outline thickness
		///
		/// \param _f The thickness
		///
		/// \see getOutlineThickness
		///
		////////////////////////////////////////////////////////////
		void setOutlineThickness(float _f);

		////////////////////////////////////////////////////////////
		/// \brief Set the text's fill color
		///
		/// \param _color The color
		///
		/// \see getTextFillColor
		///
		////////////////////////////////////////////////////////////
		void setTextFillColor(const sf::Color& _c);

		////////////////////////////////////////////////////////////
		/// \brief Set the text's outline color
		///
		/// \param _color The color
		///
		/// \see getTextOutlineColor
		///
		////////////////////////////////////////////////////////////
		void setTextOutlineColor(const sf::Color& _c);

		////////////////////////////////////////////////////////////
		/// \brief Set the text's outline thickness
		///
		/// \param _f The thickness
		///
		/// \see getTextOutlineThickness
		///
		////////////////////////////////////////////////////////////
		void setTextOutlineThickness(float _f);

		////////////////////////////////////////////////////////////
		/// \brief Get the box's color
		///
		/// \see setColor
		///
		////////////////////////////////////////////////////////////
		const sf::Color getColor() const;

		////////////////////////////////////////////////////////////
		/// \brief Get the caret's color
		///
		/// \see setCaretColor
		///
		////////////////////////////////////////////////////////////
		const sf::Color getCaretColor() const;

		////////////////////////////////////////////////////////////
		/// \brief Get the rect's outline color
		///
		/// \see setOutlineColor
		///
		////////////////////////////////////////////////////////////
		const sf::Color getOutlineColor() const;

		////////////////////////////////////////////////////////////
		/// \brief Get the rect's outline thickness
		///
		/// \see setOutlineThickness
		///
		////////////////////////////////////////////////////////////
		float getOutlineThickness() const;

		////////////////////////////////////////////////////////////
		/// \brief Get the text's fill color
		///
		/// \see setTextFillColor
		///
		////////////////////////////////////////////////////////////
		const sf::Color getTextFillColor() const;

		////////////////////////////////////////////////////////////
		/// \brief Get the text's outline color
		///
		/// \see setTextOutlineColor
		///
		////////////////////////////////////////////////////////////
		const sf::Color getTextOutlineColor() const;

		////////////////////////////////////////////////////////////
		/// \brief Get the text's outline thickness
		///
		/// \see setTextOutlineThickness
		///
		////////////////////////////////////////////////////////////
		float getTextOutlineThickness() const;

		////////////////////////////////////////////////////////////
		/// \brief Set the text's character size
		///
		/// \param _i The character size
		///
		////////////////////////////////////////////////////////////
		void setCharSize(unsigned int _i);

		////////////////////////////////////////////////////////////
		/// \brief Set the maximum amount of characters
		///
		/// \param _i The maximum amount of characters
		///
		////////////////////////////////////////////////////////////
		void setMaxChars(unsigned int _i);

		////////////////////////////////////////////////////////////
		/// \brief Toggle always-on visibility
		///
		/// If true, the text entry box will be drawn even if no
		/// text is being entered
		///
		/// \param _b The boolean value
		///
		////////////////////////////////////////////////////////////
		void setAlwaysVisible(bool _b);

		////////////////////////////////////////////////////////////
		/// \brief Toggle always-on activeness
		///
		/// If true, the text entry box will be always active and
		/// will constantly be getting text input. Additionally,
		/// text will not be cleared upon pressing RETURN.
		///
		/// \param _b The boolean value
		///
		////////////////////////////////////////////////////////////
		void setAlwaysActive(bool _b);

		////////////////////////////////////////////////////////////
		/// \brief Set the width of the text entry box
		///
		/// The height will be automatically determined depending on
		/// the character size.
		///
		/// \param _width The desired width
		///
		/// \see getWidth
		///
		////////////////////////////////////////////////////////////
		void setWidth(float _width);

		////////////////////////////////////////////////////////////
		/// \brief Get the position
		///
		////////////////////////////////////////////////////////////
		const sf::Vector2f& getPosition() const;

		////////////////////////////////////////////////////////////
		/// \brief Get the local bounds
		///
		////////////////////////////////////////////////////////////
		const sf::FloatRect getLocalBounds() const;

		////////////////////////////////////////////////////////////
		/// \brief Get the global bounds
		///
		////////////////////////////////////////////////////////////
		const sf::FloatRect getGlobalBounds() const;

		////////////////////////////////////////////////////////////
		/// \brief Gets the width of the text entry box
		///
		/// \see setWidth
		///
		////////////////////////////////////////////////////////////
		float getWidth() const;

		////////////////////////////////////////////////////////////
		/// \brief Gets the height of the text entry box
		///
		////////////////////////////////////////////////////////////
		float getHeight() const;

		////////////////////////////////////////////////////////////
		/// \brief Gets the font's line spacing value
		///
		////////////////////////////////////////////////////////////
		float getLineSpacing() const;

		////////////////////////////////////////////////////////////
		/// \brief Get input
		///
		/// \param A reference to a captured event
		///
		////////////////////////////////////////////////////////////
		void getInput(sf::Event& _event);

		////////////////////////////////////////////////////////////
		/// \brief Update
		///
		////////////////////////////////////////////////////////////
		void update();

		////////////////////////////////////////////////////////////
		/// \brief Draw the text to a render target
		///
		/// sf::Drawable overload.
		///
		/// \param target RenderTarget to draw to
		/// \param states Current render states
		///
		////////////////////////////////////////////////////////////
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		////////////////////////////////////////////////////////////
		/// \brief Is text being entered?
		///
		/// Returns whether of not the text box is active, i.e.,
		/// accepting user input.
		///
		////////////////////////////////////////////////////////////
		bool enteringText() const;

		////////////////////////////////////////////////////////////
		/// \brief Is the user's text input complete?
		///
		/// Returns true after a user has finished entering text.
		/// The last entered string can be retrieved via
		/// getLastString
		///
		/// \see getLastString
		///
		////////////////////////////////////////////////////////////
		bool inputComplete() const;

		////////////////////////////////////////////////////////////
		/// \brief Returns the last string a user has finished inputting
		///
		/// After RETURN is pressed, the contents of the text entry box
		/// are cleared and moved over to m_lastString. It can be retr-
		/// ieved via this function.
		///
		////////////////////////////////////////////////////////////
		const std::string getLastString() const;

		////////////////////////////////////////////////////////////
		/// \brief Returns the current contents of the text entry box
		///
		////////////////////////////////////////////////////////////
		const std::string getCurrentString() const;

		////////////////////////////////////////////////////////////
		/// \brief Toggles whether the text entry box is active
		///
		/// When set to true, the text entry box will accept input.
		///
		////////////////////////////////////////////////////////////
		void setActive(bool _b);

	  private:
		////////////////////////////////////////////////////////////
		/// \brief Used to denote the current selection direction
		///
		////////////////////////////////////////////////////////////
		enum class SELDIR
		{
			LEFT,
			NEUTRAL,
			RIGHT
		};

		////////////////////////////////////////////////////////////
		/// \brief Handles user input given the unicode code.
		///
		/// Depending on whether a sequence is selected, or if the
		/// key pressed is the backspace key, this function may call
		/// deleteSelection before insert
		///
		/// \see deleteSelection
		/// \see insert
		///
		////////////////////////////////////////////////////////////
		void handleInput(sf::Uint32 _unicode);

		////////////////////////////////////////////////////////////
		/// \brief Sets the text position.
		///
		/// Sets the text's position and then calls updateCaret,
		/// updateHighlight, and updateAlpha
		///
		/// \see updateCaret
		/// \see updateHighlight
		/// \see updateAlpha
		///
		////////////////////////////////////////////////////////////
		void setTextPosition(const sf::Vector2f& _pos);

		////////////////////////////////////////////////////////////
		/// \brief Sets the text's string
		///
		/// Since MulticolorText will lose its outline thickness
		/// when changing its string, we'll use this function to
		/// reset it every time we change the string. Also calls
		/// shiftTextToRight.
		///
		/// \see setOutlineThickness
		/// \see shiftTextToRight
		///
		////////////////////////////////////////////////////////////
		void setTextString(const std::string& _str);

		////////////////////////////////////////////////////////////
		/// \brief Updates the transparency of overflowing text
		///
		/// Checks for letters that are outside of the bounds of
		/// the box and makes them transparent.
		///
		////////////////////////////////////////////////////////////
		void updateAlpha() const;

		////////////////////////////////////////////////////////////
		/// \brief Updates caret's position and transparency value
		///
		/// Ensures that the caret's position is where it should be
		/// according to the user's selection. Also manages the caret's
		/// fading in/out effect.
		///
		///////////////////////////////////////////////////////////
		void updateCaret();

		////////////////////////////////////////////////////////////
		/// \brief Updates the highlighted text's rectangle
		///
		/// Manages the position and size of the selection rectangle
		/// according to the user's selection and the bounds of the box.
		///
		///////////////////////////////////////////////////////////
		void updateHighlight();

		////////////////////////////////////////////////////////////
		/// \brief Are the contents of the text entry box blank?
		///
		///////////////////////////////////////////////////////////
		bool stringEmpty() const;

		////////////////////////////////////////////////////////////
		/// \brief Selects all the contents of the text entry box
		///
		///////////////////////////////////////////////////////////
		void selectAll();

		////////////////////////////////////////////////////////////
		/// \brief Unselects all the contents of the text entry box
		///
		///////////////////////////////////////////////////////////
		void unselectAll();

		////////////////////////////////////////////////////////////
		/// \brief Moves the caret one step to the left
		///
		///////////////////////////////////////////////////////////
		void moveLeft();

		////////////////////////////////////////////////////////////
		/// \brief Moves the caret one step to the right
		///
		///////////////////////////////////////////////////////////
		void moveRight();

		////////////////////////////////////////////////////////////
		/// \brief Selects one step to the left
		///
		/// Selects the text from the caret's position to one step
		/// to the left
		///
		///////////////////////////////////////////////////////////
		void selectLeft();

		////////////////////////////////////////////////////////////
		/// \brief Selects one step to the right
		///
		/// Selects the text from the caret's position to one step
		/// to the right
		///
		///////////////////////////////////////////////////////////
		void selectRight();

		////////////////////////////////////////////////////////////
		/// \brief Shifts text to the left if neccessary
		///
		/// If the caret goes out of the right edge of the box, this
		/// function shifts the position of m_text to the left as much
		/// as neccessary to ensure that the caret is still visible.
		/// Note that text out of bounds of the box will become trans-
		/// parent.
		///
		/// Returns true if the text was shifted
		///
		/// \see updateAlpha
		///
		///////////////////////////////////////////////////////////
		bool shiftTextToLeft();

		////////////////////////////////////////////////////////////
		/// \brief Shifts text to the right if neccessary
		///
		/// If the caret goes out of the left edge of the box, this
		/// function shifts the position of m_text to the right as much
		/// as neccessary to ensure that the caret is still visible.
		/// Note that text out of bounds of the box will become trans-
		/// parent.
		///
		/// Returns true if the text was shifted
		///
		/// \see updateAlpha
		///
		///////////////////////////////////////////////////////////
		bool shiftTextToRight();

		////////////////////////////////////////////////////////////
		/// \brief Resets the text's position
		///
		/// Sets the text's X position to the box's (m_rectangle) X
		/// position.
		///
		/// \see setTextPosition
		///
		///////////////////////////////////////////////////////////
		void resetTextPosition();

		////////////////////////////////////////////////////////////
		/// \brief Returns the position of the start of the last word
		///
		/// Used when holding CTRL and "skipping" words
		///
		/// \param _from The position from which to start
		///
		///////////////////////////////////////////////////////////
		size_t posAtPreviousWord(size_t _from) const;

		////////////////////////////////////////////////////////////
		/// \brief Returns the position of the end of the next word
		///
		/// Used when holding CTRL and "skipping" words
		///
		/// \param _from The position from which to start
		///
		///////////////////////////////////////////////////////////
		size_t posAtNextWord(size_t _from) const;

		////////////////////////////////////////////////////////////
		/// \brief Are multiple letters selected?
		///
		///////////////////////////////////////////////////////////
		bool sequenceSelected() const;

		////////////////////////////////////////////////////////////
		/// \brief Delete the entirety of the current selection
		///
		///////////////////////////////////////////////////////////
		void deleteSelection();

		////////////////////////////////////////////////////////////
		/// \brief Get the contents of the current selection
		///
		///////////////////////////////////////////////////////////
		const std::string getSelection() const;

		////////////////////////////////////////////////////////////
		/// \brief Is the input valid?
		///
		/// Anything between 32 and 255 represents the  alphanumeric
		/// characters, and some symbols.
		///
		/// \see insert
		///
		///////////////////////////////////////////////////////////
		bool validInsertion(sf::Uint32 _unicode) const;

		////////////////////////////////////////////////////////////
		/// \brief Insert the string into the currently selected position
		///
		///////////////////////////////////////////////////////////
		void insert(std::string& _str);

		////////////////////////////////////////////////////////////
		/// \brief Insert the char into the currently selected position
		///
		///////////////////////////////////////////////////////////
		void insert(char _char);

		////////////////////////////////////////////////////////////
		/// \brief Clear all the contents of the text entry box
		///
		///////////////////////////////////////////////////////////
		void clearText();

		////////////////////////////////////////////////////////////
		/// \brief Increments/decrements m_selectionBegin safely
		///
		/// \param _a The value to add
		///
		///////////////////////////////////////////////////////////
		void moveSelectionBegin(int _a);

		////////////////////////////////////////////////////////////
		/// \brief Increments/decrements m_selectionEnd safely
		///
		/// \param _a The value to add
		///
		///////////////////////////////////////////////////////////
		void moveSelectionEnd(int _a);

		////////////////////////////////////////////////////////////
		/// \brief Swaps the values of m_selectionBegin/m_selectionEnd
		///
		///////////////////////////////////////////////////////////
		void swapBeginAndEnd();

		////////////////////////////////////////////////////////////
		/// \brief Returns whether the text is wider than the box
		///
		///////////////////////////////////////////////////////////
		bool textTooWide() const;

		///////////////////////////////////////////////////////////
		//Data members --------------------------------------------
		///////////////////////////////////////////////////////////

		const sf::Font&              m_font;                 ///< Font used to display the title and menu items
		sf::RectangleShape           m_rectangle;            ///< The background rectangle
		sf::RectangleShape           m_highlightedRectangle; ///< The rectangle used to highlight the current selection
		size_t                       m_selectionBegin;       ///< The beginning index of the current selection
		size_t                       m_selectionEnd;         ///< The end index of the current selection
		SELDIR                       m_selectionDirection;   ///< What direction the user is selecting text in
		mutable spss::MulticolorText m_text;                 ///< The text used to display what the user is entering
		sf::Text                     m_caret;                ///< The caret
		bool                         m_enteringText;         ///< Is the text entry box active, i.e. accepting input?
		mutable bool                 m_inputComplete;        ///< Did the user finish entering text (press RETURN)?
		bool                         m_alwaysVisible;        ///< Display the box at all times, even when m_enteringText is false?
		bool                         m_alwaysActive;         ///< m_enteringText is always set to true and prevent text from being cleared upon pressing RETURN?
		std::string                  m_lastString;           ///< The last string entered by the user (RETURN was pressed)
		unsigned int                 m_charSize;             ///< m_text's character size
		unsigned int                 m_maxChars;             ///< The maximum amount of characters that can be entered
		sf::Color                    m_textFillColor;        ///< m_text's fill color
		sf::Color                    m_textOutlineColor;     ///< m_text's outline color
		float                        m_textOutlineThickness; ///< m_text's outline thickness
		mutable bool                 m_alphaUpdateNeeded;    ///< Does the transparency need to be rechecked when next possible?
		float                        m_xOffset;              ///< The delta offset that's been applied to the text's position via the shifting left/right functions
	};

} //namespace spss
