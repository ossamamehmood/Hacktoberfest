import React, { useState, useEffect } from 'react';
import ChatMessage from './ChatMessage';

function ChatRoom() {
  const [messages, setMessages] = useState([]);
  const [newMessage, setNewMessage] = useState('');

  useEffect(() => {
    // Fetch chat messages and set them to the 'messages' state
  }, []);

  const handleSendMessage = () => {
    // Send new message to the server and update the 'messages' state
  };

  return (
    <div className="container">
      <h2>Chat Room</h2>
      <div className="messages">
        {messages.map((message, index) => (
          <ChatMessage key={index} message={message} />
        ))}
      </div>
      <div className="input-box">
        <input
          type="text"
          placeholder="Type your message..."
          value={newMessage}
          onChange={(e) => setNewMessage(e.target.value)}
        />
        <button onClick={handleSendMessage}>Send</button>
      </div>
    </div>
  );
}

export default ChatRoom;
