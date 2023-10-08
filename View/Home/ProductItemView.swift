//
//  Created by Robert Petras
//  SwiftUI Masterclass ♥ Better Apps. Less Code.
//  https://swiftuimasterclass.com 
//

import SwiftUI

struct ProductItemView: View {
  // MARK: - PROPERTY
  
  let product: Product
  
  // MARK: - BODY
  
  var body: some View {
    VStack(alignment: .leading, spacing: 6, content: {
      // PHOTO
        ZStack() {
        Image(product.image)
          .resizable()
          .scaledToFit()
          .padding(10)
       
          
      } //: ZSTACK
      .background(Color(red: product.red, green: product.green, blue: product.blue))
     
      .cornerRadius(12)

      // NAME
      Text(product.name)
        .font(.title3)
        .fontWeight(.black)
        .foregroundColor(Color(hue: 1.0, saturation: 0.067, brightness: 0.731))
 
      // PRICE
      Text(product.formattedPrice)
        .fontWeight(.semibold)
     
        .foregroundColor(colorGray)
      
    }) //: VSTACK
  }
}

// MARK: - PREVIEW

struct ProductItemView_Previews: PreviewProvider {
  static var previews: some View {
    ProductItemView(product: products[0])
      .previewLayout(.fixed(width: 200, height: 300))
      .padding()
      .background(colorBackground)
  }
}
