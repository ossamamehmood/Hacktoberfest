import React from 'react';

function ChatMessage({ message }) {
  return (
    <div className="message">
      <strong>{message.user}</strong>: {message.text}
    </div>
  );
}

export default ChatMessage;
