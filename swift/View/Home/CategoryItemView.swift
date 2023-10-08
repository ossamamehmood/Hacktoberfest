//
//  Created by Robert Petras
//  SwiftUI Masterclass ♥ Better Apps. Less Code.
//  https://swiftuimasterclass.com 
//

import SwiftUI

struct CategoryItemView: View {
  // MARK: - PROPERTY
  
  let category: Category
  
  // MARK: - BODY
  
  var body: some View {
    Button(action: {}, label: {
      HStack(alignment: .center, spacing: 6) {
        Image(category.image)
         
          .resizable()
          .scaledToFill()
          .frame(width: 40, height: 30, alignment: .center)
          .foregroundColor(.gray)
       
        Text(category.name.uppercased())
          .fontWeight(.light)
          .foregroundColor(.gray)
       
        
        Spacer()
      } //: HSTACK
      .padding()
      .background(Color.white.cornerRadius(12))
      .background(
        RoundedRectangle(cornerRadius: 12)
          .stroke(Color.gray, lineWidth: 1)
      )
    }) //: BUTTON
  }
}

// MARK: - PREVIEW

struct CategoryItemView_Previews: PreviewProvider {
  static var previews: some View {
    CategoryItemView(category: categories[0])
      .previewLayout(.sizeThatFits)
      .padding()
      .background(colorBackground)
  }
}
